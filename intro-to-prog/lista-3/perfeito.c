#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    while(n--){
        int x; scanf("%d", &x);
        int sum = 1;
        for(int i = 2; i <= x/2; i++){
            if(x % i == 0) sum+= i;
        }

        if(sum == x && x != 1) printf("%d eh perfeito\n", x);
        else printf("%d nao eh perfeito\n", x);
    }
}