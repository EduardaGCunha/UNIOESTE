#include <stdio.h>

int main(){
    int a, b; scanf("%d %d", &a, &b);
    int resultado;
    if(a == b){
        resultado = 24;
    }
    else if(a > 12 && b < 12){
        a = 24 - a;
        resultado = a + b;
    }else if(a < 12 && b > 12){
        resultado = b - a;
    }else {
        int c = b > a ? b : a;
        int d = b > a ? a : b;
        resultado = c - d;
    }

    printf("O JOGO DUROU %d HORA(S)\n", resultado);
}