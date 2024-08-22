#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char titulo[151];
    char autor[201];
    char editora[51];
    int edicao;
    int ano;
    double preco;
    int estoque;
} LIVRO; 

typedef struct No {
    LIVRO livro;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
} Lista;

void ler(LIVRO *l){
    printf("Digite o código, título, autor, editora, edição, ano, preço e estoque nessa ordem\n");
    scanf("%d%*c", &l->codigo);
    scanf("%150[^\n]%*c", l->titulo);  // Lê até 150 caracteres ou até nova linha
    scanf("%200[^\n]%*c", l->autor);   // Lê até 200 caracteres ou até nova linha
    scanf("%50[^\n]%*c", l->editora); 
    scanf("%d%*c", &l->edicao);
    scanf("%d%*c", &l->ano);
    scanf("%lf%*c", &l->preco);
    scanf("%d%*c", &l->estoque);
}

void cadastrar(Lista *lista, LIVRO livro){
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória em cadastrar.\n");
        return;
    }
    novo->livro = livro;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

// Função de inserir que será usada para ler do arquivo e colocar na lista
void inserir_lista(Lista *lista, LIVRO livro){
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória em inserir lista.\n");
        return;
    }
    novo->livro = livro;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void salvar(Lista lista){
    FILE *file = fopen("./livro.b", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo em salvar.\n");
        return;
    }
 
    No* i = lista.inicio;
    while(i != NULL){
        fwrite(&(i->livro), sizeof(LIVRO), 1, file);
        i = i->prox;
    }
    
    fclose(file);
}

void busca_por_autor(Lista lista){
    char nome[201];
    scanf("%[^\n]%*c", nome);
    printf("%s\n", nome);

    No* i = lista.inicio;

    printf("\nLivros do Autor %s\n", nome);
    while(i != NULL){
        if(strcmp(i->livro.autor, nome) == 0){
            printf("%s\n", i->livro.titulo);
        }
        i = i->prox;
    }
}

void remover_livro(Lista lista) {
    No *i = lista.inicio;
    int codigo;
    printf("\nDigite o código do livro a ser removido\n");
    scanf("%d", &codigo);
    while(i) {
        if (i->livro.codigo == codigo) {
            i->livro.codigo = -1;
            printf("\n Livro removido com sucesso\n");
            salvar(lista);
            return;
        }
        i = i->prox;
    }
    printf("\nLivro não encontrado\n");

}

void imprimir_livro(Lista lista) {
    No *i = lista.inicio;
    int codigo;
    printf("\nDigite o código do livro a ser impresso\n");
    scanf("%d", &codigo);
    while(i) {
        if (i->livro.codigo == codigo) {
            printf("\n Título: %s;", i->livro.titulo);
            printf("\n Autor: %s", i->livro.autor);
            printf("\n Editora: %s", i->livro.editora);
            printf("\n Edição: %d", i->livro.edicao);
            printf("\n Ano: %d", i->livro.ano);
            printf("\n Preço: R$ %.02lf", i->livro.preco);
            printf("\n Estoque: %d\n\n", i->livro.estoque);
        }
        i = i->prox;
    }
}

void calcular_total(Lista lista) {
    No *i = lista.inicio;
    int contador = 0;
    while(i) {
        if (i->livro.codigo != -1) contador++;
        i = i->prox;
    }
    printf("\n O número total de livros cadastrados é: %d\n ", contador);

}

void registros_livres(Lista lista) {
    No* i = lista.inicio;
    int contador = 1;
    int cnt = 0;
    while(i != NULL) {
        if(i->livro.codigo == -1) {
            printf("\nO registro de número %d está disponível para uso\n", contador);
            printf("%d" ,i->livro.codigo);
            cnt++;
        }
        contador++;
        i = i->prox;
    }

    if(cnt == 0) printf("Nenhum registro livre!\n");
    
}

void busca_por_titulo(Lista lista){
    char titulo[151];
    printf("Digite o nome do livro: ");
    scanf("%[^\n]%*c", titulo);

    No* i = lista.inicio;

    printf("\nInformações do Livro %s\n", titulo);
    while(i != NULL){
        if(strcmp(i->livro.titulo, titulo) == 0){
            printf("Código: %d\n", i->livro.codigo);
            printf("Edicao: %d\n", i->livro.edicao);
            printf("Autor: %s\n", i->livro.autor);
            printf("Editora: %s\n", i->livro.editora);
            printf("Ano: %d\n", i->livro.ano);
            printf("Estoque: %d\n", i->livro.estoque);
            printf("Preço: %lf\n", i->livro.preco);
        }
        i = i->prox;
    }
}

Lista ler_arquivo(){
    Lista lista;
    lista.inicio = NULL;
    FILE *file = fopen("./livro.b", "rb");
    if (file == NULL) {
        printf("Lista encadeada atualmente vazia.\n");
        return lista;
    }

    LIVRO livro;
    while(fread(&livro, sizeof(LIVRO), 1, file)){

        inserir_lista(&lista, livro);
    }

    fclose(file);

    return lista;
}


//eliminar os brancos
Lista carregar_arquivo(Lista lista) {
    FILE *file = fopen("arquivo.txt", "r");
    if (!file) {
        printf("Não é possível abrir o arquivo.\n");
        return lista;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        LIVRO livro;
        char *field = NULL;

        line[strcspn(line, "\n")] = '\0';

        field = strtok(line, ";");
        livro.codigo = (field ? atoi(field) : 0);

        field = strtok(NULL, ";");
        strcpy(livro.titulo, (field ? field : ""));

        field = strtok(NULL, ";");
        strcpy(livro.autor, (field ? field : ""));

        field = strtok(NULL, ";");
        strcpy(livro.editora, (field ? field : ""));

        field = strtok(NULL, ";");
        livro.edicao = (field ? atoi(field) : 0);

        field = strtok(NULL, ";");
        livro.ano = (field ? atoi(field) : 0);

        field = strtok(NULL, ";");
        livro.preco = (field ? atof(field) : 0.0);

        field = strtok(NULL, ";");
        livro.estoque = (field ? atoi(field) : 0);

        // Adiciona o livro à lista
        inserir_lista(&lista, livro);
    }
    fclose(file);
    salvar(lista);
    return lista;
}


void listar(Lista lista){
    printf("---------------LIVROS CADASTRADOS--------------\n");

    No* i = lista.inicio;
    while(i != NULL){
        if(i->livro.codigo != -1) {
            printf("Código: %d\n", i->livro.codigo);
            printf("Título: %s\n", i->livro.titulo);
            printf("Autor: %s\n", i->livro.autor);
            printf("Estoque: %d\n", i->livro.estoque);
            printf("\n");
        }

        i = i->prox;
    }
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

int main(){
    Lista lista = ler_arquivo();
    int n = 100; 

    while(n != 0){
        menu();
        scanf("%d%*c", &n);
        if(n == 1){
            LIVRO livro;
            ler(&livro);
            cadastrar(&lista, livro);
            salvar(lista);
        }else if(n == 2){
            remover_livro(lista);
        }else if(n == 3){
            imprimir_livro(lista);
        }
        else if(n == 4){
            listar(lista);
        }else if(n == 5){
            busca_por_autor(lista);
        }else if(n == 6){
            busca_por_titulo(lista);
        }else if(n == 7){
            calcular_total(lista);
        }else if(n == 8){
            lista = carregar_arquivo(lista);
            listar(lista);
        }else if(n == 9){
            registros_livres(lista);
            
        }else{
            printf("Código inválido. Tente novamente.\n");
        }
    }

    return 0;
}
