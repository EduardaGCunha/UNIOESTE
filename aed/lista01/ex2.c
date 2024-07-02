#include <stdio.h>

void rec(int n){
    if(n == -1) return;
    printf("%d ", n);
    rec(n-1);
}

int main(){
    int n; 
    scanf("%d", &n);
    rec(n);
    printf("\n");
}