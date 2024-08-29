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

int somar_intervalo(Lista *l, int a, int b){
    int res = 0;
    //printf("%d\n", l->info);
    if(l->prox != NULL){
        res += somar_intervalo(l->prox, a, b);
    }

    if(l->info >= a && l->info <= b) return res + l->info;
    else return res;
}

Lista* obter_sublista(Lista *l, int pos1, int pos2){

    Lista* l1 = NULL;
    int i = 0;
    while(l != NULL){
        if(i >= pos1 && i <= pos2){
            //printf("%d\n", l->info);
            l1 = inserir(l1, l->info);
        }
        if(i > pos2) break;
        i++;
        l = l->prox;
    }

    return l1;
}




void questao01(){
    int lista[]= {11, 7, 5, 9, 2, 6, 8, 1, 3, 15, 22};
    Lista *l;
    for(int i = 0; i < 11; i++){
        l = inserir(l, lista[i]);
    }
    int res = somar_intervalo(l, 2, 5);
    printf("%d\n", res);
    res = somar_intervalo(l, 10, 20);
    printf("%d\n", res);
    res = somar_intervalo(l, 9, 9);
    printf("%d\n", res);
    res = somar_intervalo(l, 12, 14);
    printf("%d\n", res);

}

void printar(Lista* l1){
    printf("[");
    while(l1 != NULL){
        printf("%d, ", l1->info);
        l1 = l1->prox;
    }
    printf("]\n");
}

void questao02(){
    int lista[]= {11, 7, 5, 9, 2, 6, 8, 1, 3, 15};
    Lista *l = NULL;
    for(int i = 10; i >= 0; i--){
        l = inserir(l, lista[i]);
    }

    Lista *l1 = NULL;
    l1 = obter_sublista(l, 0, 3);
    printar(l1);

    l1 = NULL;
    l1 = obter_sublista(l, 3, 7);
    printar(l1);

    l1 = NULL;
    l1 = obter_sublista(l, 4, 4);
    printar(l1);

    l1 = NULL;
    l1 = obter_sublista(l, 13, 20);
    printar(l1);
    
}

int main(){
    questao01();
    questao02();

    return 0;
}