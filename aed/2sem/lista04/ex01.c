#include <stdio.h>

int bin_search(int vet[], int n, int x){
    int l = 0, r = n-1;
    while(l < r){
        int mid = (l+r)/2;
        if(vet[mid] < x) l = mid+1;
        else r = mid;
    }
    if(vet[l] == x) return l;
    else return -1;
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
    int a = bin_search(vet, n, 3);
    if(a != -1) printf("achou\n");
    else printf("nao achou\n");
}