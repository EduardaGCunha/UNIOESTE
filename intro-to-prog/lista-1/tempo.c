#include <stdio.h>

int main(){
    int n; scanf("%d", &n);

    //n = n % (24*3600);

    int hora = (int) n / 3600;
    n %= 3600;
    int minutes = (int) n / 60;
    n %= 60;

    printf("%d:%d:%d\n", hora, minutes, n);
}