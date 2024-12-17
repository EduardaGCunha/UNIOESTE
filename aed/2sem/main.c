#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int vet[], int n, int x){
    for(int i = 0; i < n; i++){
        if(vet[i] == x) return 1;
    }
    return 0;
}

//implementacao do professor so funciona para r, enquanto a minha funcionava para ambos l e r
int busca_binaria(int vet[], int n, int x){
    int l = 0, r = n-1; 
    while(l < r){
        int mid = (l+r)/2;
        if(vet[mid] < x) l = mid+1;
        else r = mid;
    }
    //printf("%d %d %d\n", l, r, vet[r]);
    return (vet[r] == x);

}

void merge(int vet[], int l, int r, int m){
    int i, j, k, *vet_aux;
    vet_aux = malloc((r-l)*sizeof(int));
    i = l, j = m, k = 0;
    while(i < m && j < r){
        if(vet[i] <= vet[j]) vet_aux[k++] = vet[i++];
        else vet_aux[k++] = vet[j++];
    }

    while(i < m) vet_aux[k++] = vet[i++];
    while(j < r) vet_aux[k++] = vet[j++];
    for(int i = l; i < r; i++) vet[i] = vet_aux[i-l];
    free(vet_aux);
}

void merge_sort(int vet[], int l, int r){
    if(l < r-1){
        int m =(l+r)/2;
        merge_sort(vet, l, m);
        merge_sort(vet, m, r);
        merge(vet, l, r, m);
    }
} 

int busca_bin(int vet[], int n, int x){
    int e, m, d;
    e = -1, d = n;
    while(e < d - 1){
        m = (e+d)/2;
        if(vet[m] < x) e = m;
        else d = m;
    }
    printf("%d %d", e, d);
    return (vet[d] == x);
}

int separa(int vet[], int l, int r){
    int pivo;
    pivo = vet[r];
    int j = l;
    for(int k = l; k < r; k++){
        if(vet[k] <= pivo){
            int x = vet[j];
            vet[j] = vet[k];
            vet[k] = x;
            j++;
        }
    }

    vet[r] = vet[j]; 
    vet[j] = pivo;
    return j;
}

void quicksort(int vet[], int l, int r){
    int j;
    if(l < r){
        j = separa(vet, l, r);
        quicksort(vet, l, j-1);
        quicksort(vet, j+1, r);
    }
}


void bubble_sort(int vet[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j < n; j++){
            if(vet[j] < vet[j-1]){
                int x = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = x;
            }
        }
    }
}

void insertion_sort(int vet[], int n){
    //compare it to the left, until we find someone who is smaller than ourselves
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

void selection_sort(int vet[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(vet[min] > vet[j]){
                min = j;
            }
        }

        int x = vet[i];
        vet[i] = vet[min];
        vet[min] = x;
       // printf("vet[i]:%d  vet[cur]:%d\n", vet[i], vet[cur]);
    }
}

int main(){
    int n; 
    scanf("%d", &n);
    int vet[n];

    for(int i = 0; i < n; i++){
        int x; 
        scanf("%d", &x);
        vet[i] = x;
    }

    int res = busca_bin(vet, n, 4);
    if(res == 1) printf("achou\n");
    else printf("nao achou\n");

    quicksort(vet, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    
    printf("\n");
} 