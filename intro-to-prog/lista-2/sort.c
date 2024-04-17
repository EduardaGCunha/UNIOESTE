#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int d, e, f;
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
    printf("%d\n%d\n%d\n\n", d, e, f);
    printf("%d\n%d\n%d\n", a, b, c);
}