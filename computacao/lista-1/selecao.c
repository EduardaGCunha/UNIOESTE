#include <stdio.h>

int main(){
    double arr[101];
    for(int i = 0; i < 100; i++){
        double a; scanf("%lf", &a);
        if(a > 10){
            arr[i] = 1e9;
            continue;
        }
        arr[i] = a;
    }

    for(int i = 0; i < 100; i++){
        if(arr[i] == 1e9) continue;
        printf("A[%d] = %.1lf\n", i, arr[i]);
    }
}