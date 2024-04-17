#include <stdio.h>

int main(){
    double km, litro;
    scanf("%lf %lf", &km, &litro);
    
    printf("%.3lf km/l\n", km/litro);
}