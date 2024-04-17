#include <stdio.h>
#include <stdlib.h>

int main(){
    double a, b, c, e, d, f; scanf("%lf %lf %lf", &a, &b, &c);
    if(a > b && a > c){
        f = a;
        b < c ? (e = c, d = b): (e = b, d = c);
    }else if(b > c && b > a){
        f = b;
        a < c ? (e = c, d = a): (e = a, d = c);
    }else{
        f = c;
        a < b ? (e = b, d = a): (e = a, d = b);
    }
    if(f >= (d + e)){
        printf("NAO FORMA TRIANGULO\n");
        return 0;
    }
    if(f*f == e*e + d*d) printf("TRIANGULO RETANGULO\n");
    if(f*f < e*e + d*d) printf("TRIANGULO ACUTANGULO\n");
    if(f*f > e*e + d*d) printf("TRIANGULO OBTUSANGULO\n");
    if(f == e || e == d || f == d){
        if(e==d && f == e)  printf("TRIANGULO EQUILATERO\n");
        else printf("TRIANGULO ISOSCELES\n");
    }
}