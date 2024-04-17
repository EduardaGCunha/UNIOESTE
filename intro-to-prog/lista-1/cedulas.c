#include <stdio.h>

int main(){
    int n; scanf("%d", &n);

    printf("%d\n", n);
    int a = n;
    n = (int)n/100;
    printf("%d nota(s) de R$ 100,00\n", n);
    n = a - n*100;
    a = n;
    n = (int)n/50;
    printf("%d nota(s) de R$ 50,00\n", n);
    n = a - n*50;
    a = n;
    n = (int)n/20;
    printf("%d nota(s) de R$ 20,00\n", n);
    n = a - n*20;
    a = n;
    n = (int)n/10;
    printf("%d nota(s) de R$ 10,00\n", n);
    n = a - n*10;
    a = n;
    n = (int)n/5;
    printf("%d nota(s) de R$ 5,00\n", n);
    n = a - n*5;
    a = n;
    n = (int)n/2;
    printf("%d nota(s) de R$ 2,00\n", n);
    n = a - n*2;
    a = n;
    n = (int)n;
    printf("%d nota(s) de R$ 1,00\n", n);

}