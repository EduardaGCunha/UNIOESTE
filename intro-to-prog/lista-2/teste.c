#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c; scanf("%lf %lf %lf", &a, &b, &c);

    double delta = b*b - (4*a*c);
    if(delta < 0 || a == 0){
        printf("Impossivel calcular\n");
        return 0;
    }

    double test = sqrt(delta);

    printf("%lf\n", test);
    double r1 = (b*-1 + test)/(2*a);
    double r2 = (b*-1 - test)/(2*a);
    printf("R1 = %lf\nR2 = %lf\n", r1, r2);
}