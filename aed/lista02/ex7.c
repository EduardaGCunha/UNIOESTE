#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* prox;
} no;

typedef struct fila{
    int n;
    struct no* prim;
    struct no* ultimo;
}Fila;

int vazia(Fila *f){
    return (f->prim == NULL);
}

void enqueue(Fila *f, int info){
    no* queue = malloc(sizeof(no));
    queue->info = info;
    if(vazia(f)){
        f->prim = queue;
        f->ultimo = queue;
        return;
    }
    f->n++;
    f->ultimo->prox = queue;
    f->ultimo = queue;
    return;
}

void dequeue(Fila *f){
    no* queue = f->prim;
    f->n--;
    f->prim = queue->prox;
    free(queue);
    return;
}

void imprime(Fila *f){
    no* queue = f->prim;
    while(queue != NULL){
        printf("%d ", queue->info);
        queue = queue->prox;
    }
    printf("\n");
}

int main(){
    Fila *f = malloc(sizeof(Fila));
    f->n = 0;
    f->prim = NULL;
    f->ultimo = NULL;
    for(int i = 0; i < 4; i++){
        enqueue(f, i);
    }
    imprime(f);
    dequeue(f);
    imprime(f);
    free(f);
    return 0;
}