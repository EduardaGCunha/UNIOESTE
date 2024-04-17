#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[10];
    for(int i = 0; i < 10; i++){
        int a; scanf("%d", &a);
        if(a <= 10){
            arr[i] = 1;
            continue;
        }
        arr[i] = a;
    }

    for(int i = 0; i < 10; i++){
        printf("X[%d] = %d\n", i, arr[i]);
    }

}