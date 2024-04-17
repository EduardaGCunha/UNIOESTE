#include <stdio.h>

int main(){
    double a; scanf("%lf", &a);
    double v = a;
    for(int i = 0; i < 100; i++){
        printf("N[%d] = %.4lf\n", i, v);
        v = v/2;
    }
}