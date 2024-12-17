#include <stdio.h>
#include <stdlib.h> 
int selection_sort(int vet[], int n){
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(vet[min] > vet[j]) min = j;
        }

        int x = vet[i];
        vet[i] = vet[min];
        vet[min] = x;
    }
}

int bubble_sort(int vet[], int n){
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vet[i] < vet[j]){
                int x = vet[i];
                vet[i] = vet[j];
                vet[j] = x; 
            }
        }
    }
}

int insertion_sort(int vet[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(vet[j] < vet[j-1]){
                int x = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = x;
            }
        }
    }
}

void merge(int vet[], int l, int m, int r){
    int i = l, j = m, k = 0;
    int *vet_aux = malloc((r-l)*sizeof(int));
    
    while(i < m && j < r){
        if(vet[i] <= vet[j]) vet_aux[k++] = vet[i++];
        else vet_aux[k++] = vet[j++];
    }

    while(i < m) vet_aux[k++] = vet[i++];
    while(j < r) vet_aux[k++] = vet[j++];
    for(int i = l; i < r; i++)vet[i] = vet_aux[i-l];
    free(vet_aux);
}

void mergesort(int vet[], int l, int r){
    if(l < r - 1){
        int m = (l+r)/2;
        mergesort(vet, l, m);
        mergesort(vet, m, r);
        merge(vet, l, m, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    mergesort(vet, 0, n);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

}