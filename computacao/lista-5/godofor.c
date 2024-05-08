#include <stdio.h> 
#include <string.h>

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

char *key(char *s,GODOFOR a){
    sprintf(s, "%3d%3d%3d", a.p, a.k, a.m);
    return s;
} 

void sortgod(GODOFOR v[], int n){
    char key1[MAXN], key2[MAXN];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            key(key1, v[i]);
            key(key2, v[j]);
            int ret = strcmp(key1, key2);
            if(ret > 0) continue;
            if((ret == 0 && strcmp(v[i].nome, v[j].nome) < 0) || ret < 0){
                GODOFOR temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }else{
                GODOFOR temp = v[j];
                v[j] = v[i];
                v[i] = temp;
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

  
    printf("%s\n", res[0].nome);

}