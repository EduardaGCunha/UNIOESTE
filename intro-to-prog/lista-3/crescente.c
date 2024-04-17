#include <stdio.h>

int main(){
    int n;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        for(int i = 1; i < n; i++) printf("%d ", i);
        printf("%d\n", n);
    }
}