#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    int res = 1;
    for(int i = n; i >= 1; i--){
        res = res* i;
    }
    printf("%d\n", res);
}