#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no *ant;
    struct no *prox;
}Lista; 

int vazia(Lista *l){
    return (l->prox == NULL && l->ant == NULL);
}

Lista* insere(Lista *l, int info){
    Lista* l1 = malloc(sizeof(Lista));
    //na minha logica nn faz diferenca se l ja comeca vazia
    l1->ant = NULL;
    l1->prox = l;
    l1->info = info;
    if(l != NULL) l->ant = l1;
    return l1;
}


Lista* remover(Lista* l, int info){
    Lista* l1 = l;
    if(l1 != NULL && l1->info == info){
        l1 = l1->prox;
        if(l1 != NULL) l1->ant = NULL;
        free(l);
        return l1;
    }

    while(l1 != NULL && l1->info != info){
       l1 = l1->prox;
    }

    //nao achei
    if(l1 == NULL) return l;

    //intermediario
    if(l1->prox != NULL){
        l1->prox->ant = l1->ant;
        l1->ant->prox = l1->prox;
    }else{
        l1->ant->prox = NULL;
    }

    free(l1);
    return l;

}

Lista* inverter(Lista *l){
    Lista *atual = l;
    Lista *temp = NULL;

   
    while(atual != NULL){
        temp = atual->ant;
        atual->ant = atual->prox;
        atual->prox = temp;
        atual = atual->ant;
    }

    if(temp != NULL){
        l = temp->ant;
    }

    return l;

}

void concatena(Lista *l1, Lista *l2){
    Lista *aux = l1;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = l2;
    l2->ant = aux;
}

Lista* merge(Lista *l1, Lista *l2){
    Lista *l3 = malloc(sizeof(Lista*));

    while(l1 != NULL || l2 != NULL){
        if(l1 != NULL){
            l3 = insere(l3, l1->info);
            l1 = l1->prox;
        }

        if(l2 != NULL){
            l3 = insere(l3, l2->info);
            l2 = l2->prox;
        }
    }

    return l3;
}

void imprime(Lista *l){
    Lista* l1 = l;
    while(l1 != NULL){
        printf("%d ", l1->info);
        l1 = l1->prox;
    }
    printf("\n");
}

int main(){
    Lista* l = NULL;
    Lista *l2 = NULL;
    Lista *l3 = NULL;

    for(int i = 0; i < 9; i++){
        l = insere(l, i);
    }

    imprime(l);

    //intermediario
    l = remover(l, 3);
    imprime(l);
    //cauda
    l = remover(l, 8);
    imprime(l);
    //cabeca
    l = remover(l, 0);
    imprime(l);

    printf("invertendo\n");
    l = inverter(l);
    imprime(l);

    for(int i = 10; i < 15; i++){
        l2 = insere(l2, i);
    }

    concatena(l, l2);
    imprime(l);

    imprime(l2);

    for(int i = 16; i <= 20; i++){
        l3 = insere(l3, i);
    }

    l3 = merge(l2, l3);
    imprime(l3);
}