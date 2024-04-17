#include <stdio.h>
#define TEN_POWER_9 ((double)(1e9))

int main(){
    double c; scanf("%lf", &c);
  
    int b = c;
    double remainder = (c - b) * 100;

    int n = (int)c;

    printf("NOTAS:\n");
    int a = n;
    n = (int)n/100;
    printf("%d nota(s) de R$ 100.00\n", n);
    n = a - n*100;
    a = n;
    n = (int)n/50;
    printf("%d nota(s) de R$ 50.00\n", n);
    n = a - n*50;
    a = n;
    n = (int)n/20;
    printf("%d nota(s) de R$ 20.00\n", n);
    n = a - n*20;
    a = n;
    n = (int)n/10;
    printf("%d nota(s) de R$ 10.00\n", n);
    n = a - n*10;
    a = n;
    n = (int)n/5;
    printf("%d nota(s) de R$ 5.00\n", n);
    n = a - n*5;
    a = n;
    n = (int)n/2;
    printf("%d nota(s) de R$ 2.00\n", n);
    printf("MOEDAS:\n");
    n = a - n*2;
    a = n;
    n = (int)n;
    printf("%d moeda(s) de R$ 1.00\n", n);

    n = remainder;
    a = n;
    n = (int) n/50;
    printf("%d moeda(s) de R$ 0.50\n", n);
    n = a - n*50;
    a = n;
    n = (int)n/25;
    printf("%d moeda(s) de R$ 0.25\n", n);
    n = a - n*25;
    a = n;
    n = (int)n/10;
    printf("%d moeda(s) de R$ 0.10\n", n);
    n = a - n*10;
    a = n;
    n = (int)n/5;
    printf("%d moeda(s) de R$ 0.05\n", n);
    n = a - n*5;
    a = n;
    n = (int)n;
    printf("%d moeda(s) de R$ 0.01\n", n);

}