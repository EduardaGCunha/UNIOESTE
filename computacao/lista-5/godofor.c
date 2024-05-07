#include <stdio.h> 

#define MAXN 100

typedef struct {
    char nome[MAXN];
    int p;
    int m;
    int k;
} GODOFOR;

void lerdados(GODOFOR v[], int *n){
    for(int i = 0; i < *n; i++){
        scanf("%s", v[i].nome);
        scanf("%d", &v[i].p);
        scanf("%d", &v[i].k);
        scanf("%d", &v[i].m);
    }

}

void sortgod(GODOFOR v[], int n){
    for(int i = 0; i < n; i++){
        int tst = 0;
        for(int j = i+1; j < n; j++){
            if(v[i].p > v[j].p) continue;
            if(v[j].k > v[i].k)tst = 1;
            else if(v[j].m < v[i].m) tst = 1;
            else if(v[j].nome < v[i].nome) tst = 1;
            if(tst == 1){
                GODOFOR temp = v[i];
                v[i] = v[j];
                v[j] = temp;
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