#include <stdio.h>

int main(){
    double a; scanf("%lf", &a);
    double sum = 0;
    if(a >= 0 && a <= 2000.00){
        printf("Isento\n");
        return 0;
    }else if(a >= 2000.01 && a <= 3000.00){
        sum = (a - 2000)*0.08;
    }else if(a >= 3000.01 && a <= 4500.00){
        sum = (a - 3000)*0.18 + 1000*0.08;
    }else if(a >= 4500){
        sum = (a - 4500)*0.28 + 1500*0.18 + 1000*0.08;
    }
    printf("R$ %.2lf\n", sum);
}