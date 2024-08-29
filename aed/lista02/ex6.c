#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no *ant;
    struct no *prox;
}Lista; 

int vazia(Lista *l){
    return (l == NULL);
}

Lista* insere(Lista *l, int info){
    Lista* l1 = malloc(sizeof(Lista));
    l1->info = info;

    if(vazia(l)){
        l1->prox = l1;
        l1->ant = l1;
        return l1;
    }

    l1->prox = l;
    l1->ant = l->ant;
    l->ant->prox = l1;
    l->ant = l1;

    return l1;
}

Lista* remover(Lista* l, int info){
    if(vazia(l)) return NULL;

    //removi a cabeca
    Lista* l1 = l;
    if(l->info == info){
        if(l1->prox == l1){
            free(l1);
            return NULL;
        }
        l1->ant->prox = l1->prox;
        l1->prox->ant = l1->ant;
        Lista *l2 = l1->prox;
        free(l1);
        return l2;
    }

    l1 = l1->prox;
    //procurando o cara
    while(l1->prox != l && l1->info != info){
        l1 = l1->prox;
    }

    //nao encontrei
    if(l1 == l) return l;

    l1->ant->prox = l1->prox;
    l1->prox->ant = l1->ant;
    free(l1);

    return l;

}

void imprime(Lista *l){
    Lista *aux = l;
    printf("%d ", aux->info);
    aux = aux->prox;
    while(aux != l){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void concatena(Lista *l1, Lista *l2){
    Lista *aux = l1; 

    aux = aux->prox;
    while(aux->prox != l1){
        aux = aux->prox;
    }

    aux->prox = l2;
    aux = aux->prox;
    while(aux->prox != l2){
        aux = aux->prox;
    }

    aux->prox = l1;
    l1->ant = aux;
}

Lista* inverte(Lista* l){
    if (vazia(l)) return NULL;

    Lista *atual = l;
    Lista *temp = NULL;

    // Troca os ponteiros de cada nó
    do {
        temp = atual->prox;
        atual->prox = atual->ant;
        atual->ant = temp;
        atual = temp;
    } while (atual != l);

    // Atualiza a cabeça da lista
    l = l->prox;

    return l;
}

Lista* merge(Lista *l1, Lista *l2){
    Lista *aux = NULL;
    aux = insere(aux, l1->info);
    aux = insere(aux, l2->info);
    Lista *h1 = l1->prox;
    Lista *h2 = l2->prox;
    while(h1->prox != l1 || h2->prox != l2){
        if(h1 != l1){
            aux = insere(aux, h1->info);
            h1 = h1->prox;
        }
        if(h2->prox != l2){
            aux = insere(aux, h2->info);
            h2 = h2->prox;
        }
    }

    return aux;

}


int main(){
    Lista* l = NULL;
    Lista *l2 = NULL;
    Lista *l3 = NULL;
    Lista *l4 = NULL;

    for(int i = 0; i < 9; i++){
        l = insere(l, i);
    }
    imprime(l);

    l = remover(l, 3);
    imprime(l);

    l = remover(l, 8);
    imprime(l);

    l = remover(l, 0);
    imprime(l);

    for(int i = 10; i <= 15; i++){
        l2 = insere(l2, i);
    }

    concatena(l, l2);
    imprime(l);

    for(int i = 30; i <= 35; i++){
        l4 = insere(l4, i);
    }

    for(int i = 20; i <= 25; i++){
        l3 = insere(l3, i);
    }

    l4 = merge(l4, l3);
    imprime(l4);

    l4 = inverte(l4);
    imprime(l4);

     return 0;
}
