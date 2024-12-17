#include <stdio.h>

int fast_expo(int a, int b){      
    int res = 1;
    while(b > 0){
        if(b&1) res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", fast_expo(n, k));
}