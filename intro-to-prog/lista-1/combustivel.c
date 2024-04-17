#include <stdio.h>

int main(){
    double h, km; 
    scanf("%lf %lf", &h, &km);
    km = km * h;
    printf("%.3lf\n", km/12);
}