#include <stdio.h>
#include <stdlib.h>

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

typedef struct {
    LIVRO livro;
    struct No* prox;
} No;

typedef struct {
    struct No * inicio;
} Lista;

void ler(LIVRO *l){
    printf("Digite o código, título, autor, editora, edição, ano, preço e estoque nessa ordem\n");
    scanf("%d%*c", &l->codigo);
    scanf("%150[^\n]%*c", l->titulo);  // Lê até 150 caracteres ou até nova linha
    scanf("%200[^\n]%*c", l->autor);   // Lê até 200 caracteres ou até nova linha
    scanf("%50[^\n]%*c", l->editora); 
    scanf("%d%*c", &l->edicao);
    scanf("%d", &l->ano);
    scanf("%lf", &l->preco);
    scanf("%d", &l->estoque);
}

void cadastrar(Lista *lista, LIVRO livro){
    No* novo = (No*) malloc(sizeof(No));
    novo->livro = livro;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

// //inserir no comeco
// void inserir_lista(Lista *lista, LIVRO livro){
//     No* new = (No*)sizeof(No);
//     new->livro = livro;
//     new->prox = lista->inicio;
//     lista->inicio = new;
// }

void salvar(Lista lista){
    FILE *file = fopen("./livro.b", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
 
    No* i = lista.inicio;

    while(i != NULL){
        fwrite(&(i->livro), sizeof(LIVRO), 1, file);
        i = i->prox;
    }
    
    fclose(file);
}

Lista ler_arquivo(){
    Lista lista;
    lista.inicio = NULL;
    FILE *file = fopen("./livro.b", "rb");

    LIVRO livro;
    //LIVRO ant = NULL;

    while(fread(&livro, sizeof(LIVRO), 1, file)){
        cadastrar(&lista, livro);
    }

    fclose(file);

    return lista;
}

void listar(){
    
}

void menu(){
    printf("-----------MENU--------------\n");
    printf("Digite 1 para cadastrar um livro.\n");
    printf("Digite 2 para listar todos os livros.\n");
    printf("Digite 0 para sair do menu.\n");
}

int main(){
    LIVRO livro;
    Lista lista;
    lista = ler_arquivo();
    int n=100; 

    while(n != 0){
        menu();
        scanf("%d", &n);
        if(n == 1){
            ler(&livro);
            cadastrar(&lista, livro);
        }
        if(n == 2){
            lista = ler_arquivo();
            listar();
        }
    }

}