#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < 1000; i++){
        printf("N[%d] = %d\n", i, i%n);
    }
}