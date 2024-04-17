#include <stdio.h> 

int main(){
    int n; scanf("%d", &n);
    int arr[n+1];
    for(int i = 0; i < n; i++){
        int a; scanf("%d", &a);
        arr[i] = a;
    }

    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
}