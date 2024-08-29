#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no*prox;
}no;

int vazia(no* st){
    return (st == NULL);
}

no* push(no* st, int info){
    no* node = malloc(sizeof(no));
    node->info = info;
    node->prox = st;

    st = node;
    return st;
}

void imprime(no *st){
    no* node = st;
    while(st != NULL){
        printf("%d ", st->info);
        st = st->prox;
    }
    printf("\n");
}

no* pop(no* st){
    no* node = st;
    st = st->prox;
    free(node);
    return st;
}

int topo(no *st){
    return st->info;
}

int main(){
    no* node;

    for(int i = 0; i < 4; i++){
        node = push(node, i);
    }
    imprime(node);

    printf("%d\n", topo(node));

    node = pop(node);
    imprime(node);
    free(node);
}
