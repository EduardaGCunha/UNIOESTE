#include <stdio.h>

void lervetor(double arr[], int n){
    for(int i = 0; i < n; i++){
        double a; 
        scanf("%lf", &a);
        arr[i] = a;
    }
}

void encurtador(double arr[], int n, int k){
    double sum = 0;
    int ind = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if((i+1) % k == 0 || i == n-1){ 
            i == n-1 ? printf("%.2lf\n", sum/(n-1-ind)) : printf("%.2lf\n", sum/k);
            sum = 0;
            ind = i;
        }
    }
}

int main(){
    int n; 
    scanf("%d", &n);
    double arr[n]; 
    lervetor(arr, n);
    int k; 
    scanf("%d", &k);
    encurtador(arr, n, k);
    return 0; 
}
