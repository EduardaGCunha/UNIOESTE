#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAXN 100

typedef struct {
    char nome[MAXN]
} PALAVRA;

int lerdados(char *fn, PALAVRA *p[], int *n){
    FILE *arq;
    arq = fopen(fn, "r");
    if(arq == NULL) return errno;
    char str[MAXN];
    for(int i = 0; fscanf(arq, "%[^\n]%*c", str) != EOF; i++){
        p[i] = malloc(sizeof(PALAVRA));
    }
    fclose(arq);
    return 0;
}

int main(){
    int n; 
    PALAVRA p[MAXN];
}