#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* prox;
}no;

no* push(no* st, int info){
    no* node = malloc(sizeof(no));
    node->info = info;
    node->prox = st;
    return node;
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
    no* node = NULL;
    char c;
    double res = 0;
    while(scanf(" %c", &c) != EOF){
        if(c == ' ') continue;
        if(c >= '0' && c <= '9'){
            node = push(node, c - '0');
        }else{
            int a, b;
            a = topo(node);
            node = pop(node);
            b = topo(node);
            node = pop(node);
            if(c == '-') node = push(node, a - b);
            else if(c == '+') node = push(node, a+b);
            else if(c == '*') node = push(node, a*b);
            else node = push(node, a/b);
        }
    }

    printf("%d\n", topo(node));

}