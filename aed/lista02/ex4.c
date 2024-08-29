#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int info;
    struct no * prox;
} no;

typedef struct {
    struct no* cabeca;
    struct no* cauda;
}Lista;

int vazia(Lista *l){
    return (l->cabeca == NULL);
}

void inserir_cabeca(Lista *l, int info){
    no* aux = malloc(sizeof(no));
    aux->info = info;

    if(vazia(l)){
        l->cauda = aux;
    }
    aux->prox = l->cabeca;
    l->cabeca = aux;
}

void inserir_cauda(Lista *l, int info){
    no* aux = malloc(sizeof(no));
    aux->info = info;
    aux->prox = NULL;

    if(vazia(l)){
        l->cauda = aux;
        l->cabeca = aux;
    }else{
        (l->cauda)->prox = aux;
        l->cauda = aux;
    }
}

void printar(Lista *l){
    no* aux = malloc(sizeof(no*));

    aux = l->cabeca;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux= aux->prox;
    }
    printf("\n");
}

void remover(Lista *l, int info){
    if(vazia(l)) return;

    no* aux = l->cabeca;
    no* anterior = NULL;

    if(l->cabeca->info == info){
        //caso seja a cabeca, so fale que a cabeca eh igual o proximo
        l->cabeca = aux->prox;
        if(l->cabeca == NULL){
            l->cauda = NULL;
        }
        free(aux);
        return;
    }

    while(aux->info != info && aux != NULL){
        anterior = aux;
        aux = aux->prox;
    }

    if(aux == NULL) return;
    
    if(aux == l->cauda){
        l->cauda = anterior;
        anterior->prox = NULL;
    }else{
        anterior->prox = aux->prox;
    }

    free(aux);
}


int main(){
    Lista* l = malloc(sizeof(Lista));
    l->cabeca= NULL;
    l->cauda = NULL;
    int lista[] = {1, 2, 3, 4};
    int lista2[] = {9, 10, 11, 12};
    for(int i = 0; i < 4; i++){
        inserir_cabeca(l, lista[i]);
    }
    for(int i = 0; i < 4; i++){
        inserir_cauda(l, lista2[i]);
    }
    printar(l);

    remover(l, 4);
    printar(l);
    remover(l, 1);
    printar(l);
    remover(l, 12);
    printar(l);
}
