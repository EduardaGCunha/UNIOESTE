#include <stdio.h>

void lervet(int n, int arr[]){
    for(int i = 0; i < n; i++){
        int a; scanf("%d", &a);
        arr[i] = a;
    }
}

void printvet(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");  
}

int* solve(int arr[], int n){
    int arr1[n+1];
    arr1[0] = arr[n-1];
    for(int i = 1; i < n; i++){
        arr1[i] = arr[i-1];
    }
    for(int i = 0; i < n; i++){
        arr[i] = arr1[i];
    }
}

int main(){
    int n; scanf("%d", &n);
    int arr[n+1];
    lervet(n, arr);
    solve(arr, n);
    printvet(arr, n);
    return 0;
}