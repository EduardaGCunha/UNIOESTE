#include <stdlib.h>
#include "funcoes.h"

void escreverCabecalho(FILE* fb, cabecalho* cab){
    fseek(fb, 0, SEEK_SET);//aponta para o começo do ARQUIVO BINARIO
    fwrite(cab, sizeof(cabecalho), 1, fb);//copia a ESTRUTURA do cabeçalho em CAB para o que foi aponteado em FSEEK
}

cabecalho* lerCabecalho(FILE* fb){
    cabecalho *cab = (cabecalho*)malloc(sizeof(cabecalho));

    fseek(fb, 0, SEEK_SET);//aponta para o começo do ARQUIVO BINARIO
    fread(cab, sizeof(cabecalho), 1, fb);//copia a ESTUTURA do ARQUIVO BINARIA para CAB

    return cab;
}



void escreve_no(FILE* arq, no* x, int pos){
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fwrite(x,sizeof(no),1,arq);
}

no* le_no(FILE* arq, int pos) {
    no* x = malloc(sizeof(no));
    fseek(arq,sizeof(cabecalho)+ pos*sizeof(no),SEEK_SET);
    fread(x,sizeof(no),1,arq);
    return x;
}

int vazio(cabecalho *cab){
    return (cab->pos_cabeca == -1);
}

FILE* inicializa_arqbin(char* file_name) {
    FILE* fb = fopen(file_name, "r+b");

    if (fb == NULL) {
        fb = fopen(file_name, "w+b");
        inicializarLivro(fb);
    }

    return fb;
}

void cria_lista_vazia(FILE* arq){
    cabecalho * cab = (cabecalho*) malloc(sizeof(cabecalho));
    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;
    escreverCabecalho(arq,cab);
    free(cab);
}

int busca(FILE *arq, int pos_p, int pos, int cod){
    if(pos == -1)return pos_p;

    no* pai = le_no(arq, pos_p);
    printf("pos do pai atual: %d, pos_atual: %d, pai: %d, filhoesq: %d, filhodir: %d, cod: %d\n", pos_p, pos, pai->cod, pai->esq, pai->dir, cod);
    if(pai->cod <= cod){
        busca(arq, pos, pai->esq, cod);
    }else busca(arq, pos, pai->dir, cod);
}


//preciso receber a posicao inicial
void listarLivros(FILE *arq, int pos){
    if(pos == -1) return;

    no* atual = le_no(arq, pos);

    listarLivros(arq, atual->esq);

    printf("%d %s\n", atual->cod, atual->livro.titulo);

    listarLivros(arq, atual->dir);
}


void replace_comma_with_dot(char *str) {
    while (*str) {
        if (*str == ',') {
            *str = '.';
        }
        str++;
    }
}



LIVRO ler(){
    LIVRO l;
    char preco_str[20];
    printf("Digite o código, título, autor, editora, edição, ano, preço e estoque nessa ordem\n");
    scanf("%d%*c", &l.codigo);
    scanf("%150[^\n]%*c", l.titulo);  // Lê até 150 caracteres ou até nova linha
    scanf("%200[^\n]%*c", l.autor);   // Lê até 200 caracteres ou até nova linha
    scanf("%50[^\n]%*c", l.editora);
    scanf("%d%*c", &l.edicao);
    scanf("%d", &l.ano);
    scanf("%19s", preco_str); 
    scanf("%d", &l.estoque);
    replace_comma_with_dot(preco_str);    
    l.preco = atof(preco_str);  
    return l;
}


void cadastrar(FILE *arq){
    cabecalho* cab = lerCabecalho(arq);
    //printf("cab: %d\n", cab->pos_cabeca);
    LIVRO l = ler();
    if(cab->pos_cabeca == -1){
        no* nova = (no*)malloc(sizeof(no));
        nova->dir = nova->esq = -1;
        nova->cod = l.codigo;
        nova->livro = l;
        cab->pos_cabeca = 0;
        escreve_no(arq, nova, 0);
        escreverCabecalho(arq, cab);
        return;
    }
    //printf("tpo: %d\n", cab->pos_topo);
    no* arv = le_no(arq, cab->pos_cabeca);

    //se eu tiver registro livre, eu vo quere adiciona no registro livre
    printf("pos_cabeca: %d, l.codigo: %d\n", cab->pos_cabeca, l.codigo);
    int x = busca(arq, -1, cab->pos_cabeca, l.codigo);
    printf("x : %d\n", x);
    no* nova = (no*)malloc(sizeof(no));

    printf("passou do nova\n");
    nova->livro = l;
    nova->cod = l.codigo;
    nova->dir = nova->esq = -1;
    no* p = le_no(arq, x);
    printf("passou do p\n");
    cab->pos_topo++;
    if(cab->pos_livre == -1){
        escreve_no(arq, nova, cab->pos_topo);
        printf("%d %d\n", nova->cod, p->cod);
        if(nova->cod <= p->cod) p->esq = cab->pos_topo; 
        else p->dir = cab->pos_topo;
        printf("%d %d\n", p->esq, p->dir);
        escreve_no(arq, p, x);
    }else{
        escreve_no(arq, nova, cab->pos_livre);
        if(nova->cod <= p->cod) p->esq = cab->pos_livre; 
        else p->dir = cab->pos_livre;
        escreve_no(arq, p, cab->pos_livre);
    }
    escreverCabecalho(arq, cab);
    //do contrario, eu vo adiciona no pos cabtopo
    free(cab);
}


void inicializarLivro(FILE* fb) {
    cabecalho* cab = (cabecalho*)malloc(sizeof(cabecalho));

    cab->pos_cabeca = -1;
    cab->pos_topo = 0;
    cab->pos_livre = -1;

    escreverCabecalho(fb, cab);
    free(cab);
}


void menu(){
    printf("\n-----------MENU--------------\n");
    printf("Digite 1 para cadastrar um livro.\n");
    printf("Digite 2 para remover as informações de um livro.\n");
    printf("Digite 3 para imprimir dados de um livro.\n");
    printf("Digite 4 para listar todos os livros.\n");
    printf("Digite 5 para buscar livros de algum autor.\n");
    printf("Digite 6 para buscar por algum livro.\n");
    printf("Digite 7 para calcular o total de livros cadastrados\n");
    printf("Digite 8 para carregar livros.\n");
    printf("Digite 9 para imprimir lista de registros livres\n");
    printf("Digite 0 para sair do menu.\n");
    printf("----------------------------\n");
}




