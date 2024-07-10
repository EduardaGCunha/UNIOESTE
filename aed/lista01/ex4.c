#include <stdio.h>

int fatorial(int n){
    if(n == 1) return 1;
    return fatorial(n-1)*n;
}

int superfatorial(int n){
    if(n == 1) return 1;

    return fatorial(n)*superfatorial(n-1);
}

int main(){
    int n; 
    scanf("%d", &n);
    int a = superfatorial(n);
    printf("%d\n", a);
}