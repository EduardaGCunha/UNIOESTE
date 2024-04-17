#include <stdio.h>
#include <stdlib.h>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    if(a == b || b == c || a == c){
        printf("Empate\n");
        return 0;
    }
    else if(a > b && a > c){
        b < c ? printf("Bruno\n") : printf("Ian\n");
        return 0;
    }else if(b > c && b > a){
        a < c ? printf("Otavio\n"): printf("Ian\n");
        return 0;
    }else{
        a < b ? printf("Otavio\n") : printf("Bruno\n");
        return 0;
    }

}