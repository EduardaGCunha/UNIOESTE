#include <stdio.h>
#include <stdlib.h>

typedef struct livro {
    int codigo;
    char titulo[151];
    char autor[201];
    char editora[51];
    int edicao;
    int ano;
    double preco;
    int estoque;
    struct livro *node;
} LIVRO; 

void cadastrar(FILE *arq){
    LIVRO l;
    printf("Digite o código, título, autor, editora, edição, ano, preço e estoque nessa ordem\n");
    scanf("%d%*c", &l.codigo);
    scanf("%150[^\n]%*c", l.titulo);  // Lê até 150 caracteres ou até nova linha
    scanf("%200[^\n]%*c", l.autor);   // Lê até 200 caracteres ou até nova linha
    scanf("%50[^\n]%*c", l.editora); 
    scanf("%d%*c", &l.edicao);
    scanf("%d", &l.ano);
    scanf("%lf", &l.preco);
    scanf("%d", &l.estoque);

    fwrite(&l, sizeof(LIVRO), 1, arq);
}


void listar(FILE *arq){
    LIVRO l;
    rewind(arq);
    printf("\n------------------LISTANDO TODOS OS LIVROS--------------\n");
    int i = 0;
    while (fread(&l, sizeof(LIVRO), 1, arq) == 1) {
        i++
        //printf("          LIVRO %d         \n", &i);
        printf("Código: %d\n", l.codigo);
        printf("Título: %s\n", l.titulo);
        printf("Autor: %s\n", l.autor);
        printf("Editora: %s\n", l.editora);
        printf("Edição: %d\n", l.edicao);
        printf("Ano: %d\n", l.ano);
        printf("Preço: %.2lf\n", l.preco);
        printf("Estoque: %d\n", l.estoque);
        printf("                             \n");
    }
}

int main(){
    int n=100; 

    FILE *arq;

    arq = fopen("arquivo.dat", "w+b");
    if(arq == NULL){
        printf("Não foi possível ler o arquivo.\n");
        return 0;
    }

    while(n != 0){
        if(n == 1) cadastrar(arq);
        if(n == 2) listar(arq);
        printf("-----------MENU--------------\n");
        printf("Digite 1 para cadastrar um livro.\n");
        printf("Digite 2 para listar todos os livros.\n");
        printf("Digite 0 para sair do menu.\n");
        scanf("%d", &n);
    }
}