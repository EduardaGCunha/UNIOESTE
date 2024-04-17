#include <stdio.h>

int main(){
    int a = 0, b = 0, c = 0, n;
    while(1){
        scanf("%d", &n);
        if(n > 4 || n < 1 ) continue;
        if(n == 4) break;
        if(n == 1) a++;
        else if(n==2) b++;
        else c++;
    }

    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", a);
    printf("Gasolina: %d\n", b);
    printf("Diesel: %d\n", c);
}