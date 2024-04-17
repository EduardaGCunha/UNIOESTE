#include <stdio.h>

int main(){
    int n, tw =0, thr=0, fr=0, fv=0; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a; scanf("%d", &a);
        if(a%2 == 0) tw++;
        if(a%3 == 0) thr++;
        if(a%4 == 0) fr++;
        if(a%5 == 0) fv++;
    }

    printf("%d Multiplo(s) de 2\n", tw);
    printf("%d Multiplo(s) de 3\n", thr);
    printf("%d Multiplo(s) de 4\n", fr);
    printf("%d Multiplo(s) de 5\n", fv);
}