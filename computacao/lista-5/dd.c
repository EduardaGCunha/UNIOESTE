#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXL 100
#define MAXC 20
 
typedef struct{
    char nome[MAXC];
    int idade;
} DUENDE;
 
void lerdados (DUENDE d[], int *n){
    int i;
    scanf("%d%*c", n);
    for(i=0; i<*n; i++){
        scanf("%s %d", d[i].nome, &d[i].idade);
        //scanf("%d%*c", &d[i].idade);
    }

    // for(int i = 0; i < *n; i++){
    //     printf("%s %d\n", d[i].nome, d[i].idade);
    // }
}
 
void trocar(DUENDE *dx, DUENDE *dy){
    DUENDE temp;
    temp = *dx;
    *dx = *dy;
    *dy = temp;
}
 
void ordenaridades(DUENDE d[], int n){
    int i, j;
    for(i=n-1; i>0; i--)
        for(j=0; j<i; j++)
            if(d[j].idade < d[j+1].idade)
                trocar(&d[j], &d[j+1]);
            else if(d[j].idade == d[j+1].idade){
                if(strcmp(d[j].nome, d[j+1].nome) > 0){
                    trocar(&d[j], &d[j+1]);
                }
            }
}
 
void pdados(DUENDE d[], int ini, int fim, int m){
    printf("Time %d\n", ini+1);
    for(int i = ini; i < fim; i += m){
        printf("%s %d\n", d[i].nome, d[i].idade);
    }
}
 
void ptimes(DUENDE d[], int n){
    int i;
    int nt = n / 3;
    for(i=0; i<nt; i++){
        pdados(d, i, n, nt);
        printf("\n");
    }
}
 
 
int main(){
    DUENDE d[MAXL];
    int n;
    lerdados(d, &n);
    ordenaridades(d, n);
    ptimes(d, n);
 
    return 0;
}