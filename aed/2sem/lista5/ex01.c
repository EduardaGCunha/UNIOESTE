#include <stdio.h>
#include <stdlib.h>

#define TAM 1000
const int MAXN = 1e5;
// tamanho da tabela
typedef int TipoChave;
typedef struct {
    int matricula;
    char nome[50];
} TipoRegistro;

typedef struct Lista {
    TipoRegistro r; 
    struct Lista *prox;
} Lista;

typedef struct{
    Lista* l;
}slot;


typedef slot TabelaHash[TAM];

int hash(int k){
    return k%TAM;
}

void inicializaTabelaHash(TabelaHash T){
    for(int i = 0; i < TAM; i++){
       T[i].l = NULL;
    }
}

void inserir(TabelaHash T, TipoChave k, TipoRegistro r){
    int x = hash(k);
    Lista *l = (Lista *) malloc(sizeof(Lista));
    l->r = r;
    l->prox = T[x].l;
    T[x].l = l;
}

int buscar(TabelaHash T, TipoChave k){
    int x = hash(k);
    Lista *l = T[x].l;
    while(l != NULL){
        if(l->r.matricula == k) return x;
        l = l->prox;
    }
    return -1;
}

void remover(TabelaHash T, TipoChave k){
    int x = buscar(T, k);
    if(x != -1){
        Lista *l = T[x].l;
        Lista *prev = NULL;
        while(l->r.matricula != k){
            prev = l;
            l = l->prox;
        }

        if(prev == NULL){
            T[x].l = l->prox;
        }else{
            prev->prox = l->prox;
        }
        free(l);
        free(prev);
    }
}

void imprime(TabelaHash T){
    for (int i = 0; i < TAM; i++)
    {
        Lista *l = T[i].l;     
        Lista *tmp = NULL;
        while(l != NULL){
            printf("posição: %d - chave: %d, contem o registro: %d %s\n", i, l->r.matricula, l->r.matricula, l->r.nome);
            tmp = l;
            l = l->prox;
            free(tmp);
        }        
    }
    
}


int main(){
    TabelaHash th;
    inicializaTabelaHash(th);

    TipoRegistro reg1 = {12345, "Alice"};
    inserir(th, 12345, reg1); 
    
    TipoRegistro reg2 = {67890, "Bob"};
    inserir(th, 67890, reg2); 
    
    TipoRegistro reg3 = {345, "Charles"};
    inserir(th, 345, reg3);

    imprime(th);
}