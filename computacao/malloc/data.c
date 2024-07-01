#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 100


typedef struct {
    char nome[MAXN];
    int dia, mes, ano;
} PESSOA;

int lerdados(char *fn, PESSOA *v[], int *np){
    int i = 0; char str[MAXN];
    FILE *arq; 
    arq = fopen(fn, "r");
    if(arq == NULL) return errno;
    for(i = 0; fscanf(arq, "%[^;]%*c", str) != EOF; i++){
        v[i] = malloc(sizeof(PESSOA));
        strcpy(v[i]->nome, str);
        fscanf(arq, "%d %d %d%*c", &v[i]->dia, &v[i]->mes, &v[i]->ano);
    }
    *np = i;
    fclose(arq);
    return 0;
}

int relat(char *fn, PESSOA *v[], int n){
    FILE *arq;
    arq = fopen(fn, "w");
    if(arq == NULL) return errno;

    fprintf(arq, "               NOME                DATA\n");
    for(int i = 0; i < n; i++){
        fprintf(arq, "%-25s  %02d/%02d/%04d\n", v[i]->nome, v[i]->dia, v[i]->mes, v[i]->ano);
    }
    fclose(arq);
    return 0;
}

void liberar(PESSOA *v[], int n){
    for(int i = 0; i < n; i++){
        free(v[i]);
    }
}


int main(){
    PESSOA *p[MAXN];
    int n;
    lerdados("datasnasc.txt", p, &n);
    relat("teste.txt", p, n);
    liberar(p, n);
}