
#include <stdio.h>
#include <math.h>

double exp_fun(double n){
    if(n == 0) return 1;

    return pow(n, exp_fun(n-1));
}

int main(){
    double n; 
    scanf("%lf", &n);
    double a = exp_fun(n);
    printf("%lf", a);
}