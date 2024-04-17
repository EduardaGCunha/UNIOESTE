#include <stdio.h>

int main(){
    while(1){
        int n, m; scanf("%d %d", &n, &m);
        if(n == 0 || m == 0){
            printf("\n"); return 0;
        }
        if(n > 0 && m > 0) printf("primeiro\n");
        else if(n < 0 && m > 0) printf("segundo\n");
        else if(n < 0 && m < 0) printf("terceiro\n");
        else printf("quarto\n");
    }
}