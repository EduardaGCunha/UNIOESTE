#include <stdio.h>
#include <string.h>

#define MAXN 100

typedef struct {
    char nome[MAXN];
    char c[MAXN];
    char s;
} shirt;

void lerdados(shirt v[], int n){
    for(int i = 0; i < n; i++){
        scanf("%[^\n]%*c", v[i].nome);
        scanf("%s ", v[i].c);
        scanf("%c%*c", &v[i].s);
    }
    for(int i = 0; i < 2*n; i++){
        printf("%s %s %c\n", v[i].nome, v[i].c, v[i].s);
    }
}

int tam(char a){
    if(a == 'P') return 1;
    else if(a=='M') return 2;
    else return 3;
}

char *key(char *s, shirt v){
    sprintf(s, "%s%d%s", v.c, tam(v.s), v.nome);
    return s;
}

void exchange(shirt v[], int i, int j){
    shirt temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

void sortval(shirt v[], int n){
    char key1[MAXN], key2[MAXN];
    for(int i = 0; i < n -1; i++){
        for(int j = i+1; j < n; i++){
            if(strcmp(key1, key2) > 0){
                exchange(v, i, j);
            }
        }
    }
}

void printord(shirt v[], int n){
    for(int i = 0; i < n; i++){
        printf("%s\n", v[i].nome);
    }
}

int main(){
    int n;
    while(scanf("%d%*c", &n) != 0){
        shirt cam[MAXN];
        lerdados(cam, n);
        sortval(cam, n);
        printord(cam, n);
    }
}