#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAXN 100

typedef struct {
    char nome[MAXN];
    int p;
    int m;
    int k;
} GODOFOR;

void lerdados(GODOFOR v[], int *n){
    for(int i = 0; i < *n; i++){
        scanf("%s %d %d %d", v[i].nome, &v[i].p, &v[i].k, &v[i].m);
    }

}

void exchange(GODOFOR v[], int i, int j){
    GODOFOR temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

char *key(char *s,GODOFOR a){
    sprintf(s, "%3d%3d%3d", a.p, a.k, abs(100 - a.m));
    return s;
}

void sortgod(GODOFOR v[], int n){
    char key1[MAXN], key2[MAXN];
    for(int i = 0; i < n; i++){
        int tst = 0;
        for(int j = i+1; j < n; j++){   
            key(key1, v[i]); key(key2, v[j]);
            int ret = strcmp(key1, key2);
            if(ret > 0){
                exchange(v, i, j);
            }else if(ret == 0){
                if(strcmp(v[i].nome, v[j].nome) < 0){
                    exchange(v, i, j);
                }
            }
        }
    }
}

int main(){
    int n; 
    scanf("%d", &n);
    GODOFOR res[MAXN]; 
    lerdados(res, &n);
    sortgod(res, n);
    printf("%s\n", res[n-1].nome);

}