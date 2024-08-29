// estrutura de n´o para lista encadeada
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct no {
int info;
struct no *prox;
} Lista;

bool vazia(Lista * l){
    if(l == NULL) return true;
    else return false;
}

//insere um novo nó no inicio da lista
Lista* insere(Lista* l, int info){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(novo == NULL){
        printf("Erro ao alocar memoria\n");
        return l;
    }

    novo->info = info;
    novo->prox = l;
    return novo;
}

//remove um elemento da lista
Lista* rm(Lista* l, int info){
    Lista* anterior = NULL;
    Lista *atual = l;

    while(atual != NULL){
        if(atual->info == info){
            if(anterior == NULL){
                //first element to be removed;
                Lista *temp = atual;
                l = atual->prox; 
                free(temp);
            }else{
                anterior->prox = atual;
                free(atual);
            }
            return l;
        }
        anterior = atual;
        atual = atual->prox; 
    }

}
void imprime(Lista* l){
    Lista* atual = l;
    while(atual != NULL){
        printf("%d -> ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

Lista* inverte(Lista* l){
    Lista *proximo = NULL;
    Lista *atual = l;
    Lista *anterior = NULL;
    while(atual != NULL){
        proximo = atual->prox; 
        atual->prox = anterior;
        anterior = atual; 
        atual = proximo;
    }
    return anterior;
}

Lista* concatena(Lista* l1, Lista* l2){
    if(vazia(l1)) return l2;
    if(vazia(l2)) return l1;

    Lista* atual = l1;
    while(atual->prox != NULL){
        atual = atual->prox;
    }
    atual->prox = l2;
    return l1;
}

int main(){
    Lista* l1 = NULL;
    Lista* l2 = NULL;
    Lista* l3 = NULL;


    for(int i = 0; i < 4; i++){
        l1 = insere(l1, i);
    }
    for(int i = 7; i < 10; i++){
        l2 = insere(l2, i);
    }
    imprime(l1);
    imprime(l2);
    l1 = concatena(l1, l2);
    imprime(l1);

    l3 = merge(l1, l2);
    imprime (l3);
}