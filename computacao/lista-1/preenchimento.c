#include <stdio.h>

int main(){
    int arr[10];
    int n; scanf("%d", &n);
    arr[0] = n;
    for(int i = 1; i < 10; i++){
        arr[i] = arr[i-1]*2;
    }
    
    for(int i = 0; i < 10; i++){
        printf("N[%d] = %d\n", i, arr[i]);
    }
    return 0;
}