#include <stdio.h>


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    //selection sort de somente os k primeiros elementos
    for(int i = 0; i < k; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(vet[min] > vet[j]) min = j;
        }
        int x = vet[min];
        vet[min] = vet[i];
        vet[i] = x;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}