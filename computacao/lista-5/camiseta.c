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
}

int tam(char a){
    if(a == 'P') return 1;
    else if(a=='M') return 2;
    else return 3;
}

void exchange(shirt v[], int i, int j){
    shirt temp = v[j];
    v[j] = v[i];
    v[i] = temp;
}

int tst(shirt v, shirt u){
    int ret = strcmp(v.c, u.c);
    if(ret < 0) return 0;
    if(ret > 0) return 1;
    else{
        if(tam(v.s) < tam(u.s)) return 0;
        else if(tam(v.s) == tam(u.s)){
            if(strcmp(v.nome, u.nome) > 0) return 1;
            else return 0;
        }else return 1;
    }
    return 0;
}

void sortval(shirt v[], int n){
    char key1[MAXN], key2[MAXN];
    for(int i = 0; i < n -1; i++){
        for(int j = i+1; j < n; j++){
            if(tst(v[i], v[j]) == 1) exchange(v, i, j);
        }
    }
}

void printord(shirt v[], int n){
    for(int i = 0; i < n; i++){
        printf("%s %c %s", v[i].c, v[i].s, v[i].nome);
        if(i < n - 1) printf("\n");
    }
}

int main(){
    int n;
    while(scanf("%d%*c", &n)&& n!= 0){
        shirt cam[MAXN];
        lerdados(cam, n);
        sortval(cam, n);
        printord(cam, n);
        if(n) printf("\n");
    }
}