#include <stdio.h>

int rec(int n){
    if(n <= 0) return 0; 
    return rec(n/10) + n%10;
}

int main(){
    int n; 
    scanf("%d", &n);
    int a = rec(n);
    printf("%d\n", a);
}