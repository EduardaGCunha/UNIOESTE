#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max(a,b) (a>b)? a:b

struct no {
    int info;
    struct no* esq;
    struct no* dir;
};

typedef struct no* arvore;

int vazia(arvore r) {return (r == NULL);}

typedef struct queue {
    arvore val;
    struct queue* prox;
}queue;  

typedef struct Queue{
    queue* topo;
    queue* rear;
}Queue;

void initQueue(Queue* q){
    q->topo = NULL;
    q->rear = NULL;
}

int isEmpty(Queue* q) {
    return (q->topo == NULL);
}

int fast_expo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res *= a;
        a *= a;
        b/=2;
    }
    return res;
}

void enqueue(Queue* q, arvore val){
    queue* temp = (queue*) malloc(sizeof(queue));
    temp->val = val;
    temp->prox = NULL;
    if(isEmpty(q)){
        q->topo = temp;
        q->rear = temp;
    }else{
        q->rear->prox = temp;
        q->rear = temp;
    }
}

arvore dequeue(Queue *q){
    if(isEmpty(q)) return NULL;
    arvore x = q->topo->val;
    queue* temp = q->topo;
    q->topo = q->topo->prox;
    free(temp);
    return x;
}

void imprime_por_niveis(arvore st){
    Queue q;
    initQueue(&q);
    enqueue(&q, st);
    while(!isEmpty(&q)){
        int cnt = 0;
        queue* pq = &q.topo;
        while(pq != NULL){
            cnt++;
            pq = pq->prox;
        }

        for(int i = 0; i < cnt; i++){
            arvore r = dequeue(&q);
            printf("%d ", r->info);
            if(!vazia(r->esq)) enqueue(&q, r->esq);
            if(!vazia(r->dir)) enqueue(&q, r->dir);
        }
        printf("\n");
    }
}

arvore insere(arvore r, int x){
    if(vazia(r)){
        r = (struct no*) malloc(sizeof(struct no));
        r->info = x;
        r->dir = NULL;
        r->esq = NULL;
    }else if(x < r->info) r->esq = insere(r->esq, x);
    else r->dir = insere(r->dir, x);
    return r;
}

int soma(arvore r){
    if(vazia(r)) return 0;
    return soma(r->dir) + soma(r->esq) + r->info;
}

void in_order(arvore r){
    if(!vazia(r)){
        in_order(r->esq);
        printf("%d ", r->info);
        in_order(r->dir);
    }
}

void pre_order(arvore r){
    if(!vazia(r)){
        printf("%d ", r->info);
        pre_order(r->esq);
        pre_order(r->dir);
    }
}

void pos_order(arvore r){
    if(!vazia(r)){
        pos_order(r->esq);
        pos_order(r->dir);
        printf("%d ", r->info);
    }
}

int maximo(arvore r){
    if(vazia(r->dir)) return r->info;
    maximo(r->dir);
}

int minimo(arvore r){
    if(vazia(r->esq)) return r->info;
    minimo(r->esq);
}

arvore remove_arvore(arvore r, int x){
    if(vazia(r)) return NULL;
    if(x < r->info)  r->esq = remove_arvore(r->esq, x);
    else if(x > r->info) r->dir = remove_arvore(r->dir, x);
    else{//achei
        //3 casos: nenhum filho, 1 filho ou 2 filhos
        if(r->dir == NULL && r->esq == NULL){
            free(r);
            r = NULL;
        }else if(r->esq == NULL){
            r->info = minimo(r->dir);
            r->dir = remove_arvore(r->dir, r->info);
        }else{
            r->info = maximo(r->esq);
            r->esq = remove_arvore(r->esq, r->info);
        }
    }
    return r;
}


int altura(arvore r, int cnt){
    if(vazia(r)) return cnt;
    return max(altura(r->esq, cnt+1), altura(r->dir, cnt+1));
}


void imprime(arvore r, int h){
    if(vazia(r)) return;
    if(h == 1){
        printf("%d ", r->info);
    }else if(h > 1){
        imprime(r->esq, h-1);
        imprime(r->dir, h-1);
    }
}

void imprime_niveis_aux(arvore r){
    if(vazia(r)) return;
    int h = altura(r, 0);
    printf("%d\n", h);
    for(int i = 1; i < h; i++){
        imprime(r, i);
        printf("\n");
    }
}

//contar totais
int contador(arvore r){
    if(vazia(r)) return 0;
    return contador(r->esq) + contador(r->dir) + 1;
}

//estritamente binaria
int binaria(arvore r){
    if(vazia(r)) return 1;
    if(r->dir != NULL && r->esq != NULL){
        if(binaria(r->esq) && binaria(r->dir)) return 1;
        else return 0;
    }else if(r->dir == NULL && r->esq == NULL) return 1;
    return 0;
}


int main(){
    int n; 
    scanf("%d", &n);
    arvore a = NULL;
    while(n--){
        int x; 
        scanf("%d", &x);
        a = insere(a, x);
    }

    pre_order(a);
    printf("\n");
    in_order(a);
    printf("\n");
    pos_order(a);
    printf("\n");

   // imprime_por_niveis(a);

    printf("maximo: %d\n", maximo(a));
    printf("minimo: %d\n", minimo(a));
    printf("soma: %d\n", soma(a));
    printf("altura: %d\n", altura(a, 0));
    int x = contador(a);
    int y = altura(a, 0);
    printf("%d %d\n", x, y);
    if((fast_expo(2,y) - 1) == x) printf("cheia\n");
    else printf("nao cheia\n");
    if(binaria(a)) printf("é binária\n");
    else printf("não é binária\n");

   imprime_por_niveis(a);

}


