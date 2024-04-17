#include <stdio.h>

int main(){
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    a = a == 0? 24 : a;
    b = b == 0? 24 : b;
    c = c == 0? 24 : c;
    int sum = a + b + c == 24 ? printf("0\n") : printf("%d\n", (a + b + c)%24);
}