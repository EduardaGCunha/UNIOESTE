#include <stdio.h>

int main(){
    double a, b; scanf("%lf %lf", &a, &b);

    if(a == 0 && b == 0){
        printf("Origem\n");
        return 0;
    }else if(a == 0 && b != 0){
        printf("Eixo Y\n");
        return 0;
    }else if(a != 0 && b == 0){
        printf("Eixo X\n");
        return 0;
    }
    
    a < 0 ? (b < 0 ? printf("Q3\n") : printf("Q2\n")) : (b < 0 ? printf("Q4\n") : printf("Q1\n"));
}