#include <stdio.h>

int rec(int n){
    if(n == 0){
        printf("%d ", n);
        return 0;
    }

    int a = rec(n-1)+1;
    printf("%d ", a);
    return a;
}

int main(){
    int n; 
    scanf("%d", &n);
    rec(n);
    printf("\n");
    return 0;
}