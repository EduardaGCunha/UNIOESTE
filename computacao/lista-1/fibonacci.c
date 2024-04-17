#include <stdio.h>

int main(){
    long long int t; scanf("%lld", &t);
    long long int fib[61];
    fib[0] = 0; fib[1] = 1;
    for(int i = 2; i < 61; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    while(t--){
        long long int n; scanf("%lld", &n);
        printf("Fib(%lld) = %lld\n", n, fib[n]);
    }
}
