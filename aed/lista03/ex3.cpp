#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int v1, v2;
    struct no * prox;
} no;

typedef struct {
    struct no* cabeca;
    struct no* cauda;
}Lista;


void inserir_cabeca(Lista *l, int info){
    no* aux = l->cabeca;
    
}
