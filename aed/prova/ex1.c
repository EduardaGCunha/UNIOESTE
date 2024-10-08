#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no * prox;
} Lista;

int vazia(Lista *l){
    return (l == NULL);
}

Lista* inserir(Lista *l, int info){
    Lista *aux = (Lista*) malloc(sizeof(Lista));
    aux->info = info;
    aux->prox = l;
    return aux;
}

int qtd_distintos(Lista *l){
    Lista *aux = l;
    if(aux == NULL) return 1;
    if(aux->prox == NULL) return 1;

    while(aux != NULL){
        while(aux->prox->info == l->info){
            aux->prox = aux->prox->prox;
        }
        aux = aux->prox;
    }
    return qtd_distintos(l->prox)+1;
}

void printar(Lista* l1){
    printf("[");
    while(l1 != NULL){
        printf("%d, ", l1->info);
        l1 = l1->prox;
    }
    printf("]\n");
}

int main(){
    int lista[]= {7, 11, 5, 3, 8, 5, 9, 3, 3};
    Lista *l = malloc(sizeof(Lista*));
    for(int i = 0; i < 11; i++){
        l = inserir(l, lista[i]);
    }
    printar(l);
    int a = qtd_distintos(l);
    printf("%d", a);
}