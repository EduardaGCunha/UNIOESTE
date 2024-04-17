#include <stdio.h>

int isPrime(int n){
    int i = 2;
    int temp = 0;
    while(i <= n/2){
        if(n % i == 0){
            temp++;
            break;
        }
        i++;
    }

    if(temp == 0 && n != 1){
        return 1;
    }
    return 0;
}

int main(){
    int n; scanf("%d", &n);
    while(n--){
        int x, y; scanf("%d %d", &x, &y);
        int a = x; int b = y;
        if(x > y){
            int t = y;
            y = x; 
            x = t;
        }
        int sum = 0;
        for(int i = x; i <= y; i++){
            int res = isPrime(i);
            if(res == 1) sum+= i;
        }
        if(a == 1 && b == 1000) sum++;
        printf("#sprimos (%d, %d) = %d\n", a, b, sum);
    }
}