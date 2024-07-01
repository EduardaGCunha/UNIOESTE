#include <stdio.h>

void rec(int n){
    if(n == 0){
        printf("%d", &n);
    }

    return rec(n-1);
}

int main(){
    int n; 
    scanf("%d", &n);
}