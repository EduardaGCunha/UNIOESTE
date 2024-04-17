#include <stdio.h>

int main(){
    int x, y, z; scanf("%d %d %d", &x, &y, &z);
    int sum = 0;
    if(y < 0){
        sum += y;
    }
    if(x < 0){
        sum += x;
    }
    if(z < 0){
        sum += z;
    }

    printf("Soma dos negativos = %d\n", sum);
}