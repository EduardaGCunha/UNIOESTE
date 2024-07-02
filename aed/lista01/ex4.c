#include <stdio.h>


int rec(int n){
    if(n == 1) return 1;
    return rec(n-1)*n;
}
int main(){
    int n; 
    scanf("%d", &n);
    int a = rec(n);
    printf("%d\n", a);
}