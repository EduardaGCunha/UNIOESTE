#include <stdio.h>
#include <string.h>

#define MAXN 1000

typedef struct {
    char nome[MAXN];
    int dis;
    char pos;
} van;

void lerdados(van v[], int n){
    for(int i = 0; i < n; i++){
        scanf("%s %c %d", v[i].nome, &v[i].pos, &v[i].dis);
    }
}

void exchange(van v[], int i, int j){
    van temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

char *key(char *s,van a){
    sprintf(s, "%5d%c%-25s", a.dis, a.pos, a.nome);
    return s;
}

void sortval(van v[], int n){
    char key1[MAXN], key2[MAXN];
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            key(key1, v[i]);
            key(key2, v[j]);
            if(strcmp(key1, key2) > 0){
                exchange(v, i, j);
            }
        }
    }
}

void printord(van v[], int n){
    for(int i = 0; i < n; i++){
        printf("%s\n", v[i].nome);
    }
}


int main(){
    int n;
    scanf("%d", &n);
    van alunos[MAXN];
    while(scanf("%d%*c", &n) != EOF){
        lerdados(alunos, n);
        sortval(alunos, n);
        printord(alunos, n);
    }    
}