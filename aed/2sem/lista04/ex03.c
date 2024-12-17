#include <stdio.h>

//selection sort seleciona um cara atual e vai trocando

//ent para cada elemento, eu devo selecionar 

void selection_sort(int vet[], int st, int n){
    if(st >= n - 1) return;

    int min = st;
    for(int i = st+1; i < n; i++){
        if(vet[i] < vet[min]) min = i;
    }

    int x  = vet[st];
    vet[st] = vet[min];
    vet[min] = x;
    selection_sort(vet, st+1, n);
}

int main(){
    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    selection_sort(vet, 0, n);
    for(int i = 0; i < n; i++) printf("%d ", vet[i]);
    printf("\n");
}