#include <stdio.h>

double cat(int n){
    if(n == 0) return 1;
    return (2*(2*n-1)/(n+1))*cat(n-1);
}

int main(){
    int n; 
    scanf("%d", &n);
    double a = cat(n);
    printf("%lf", a);
}