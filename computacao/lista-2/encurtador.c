#include <stdio.h>

void encurtador(int arr[], int m, int n){
    double sum = 0;
    for(int i = 1; i <= n-1; i++){
        sum += arr[i];
        if(i%m == 0){
            printf("%.2lf\n", (sum/m));
            sum = 0;
        }
    }
    if(n%m != 0){
        double sum = 0;
        int i = 0;
        for(i = n; i > n - m + 1; i--){
            sum += arr[i];
        }
        printf("%.2lf\n", (sum/ (n - i)));
    }
}


int main(){
    int n; scanf("%d", &n);
    int arr[n+1];
    for(int i = 1; i <= n; i++){
        int a; scanf("%d", &a);
        arr[i] = a;
    }
    int m; scanf("%d", &m);
    encurtador(arr, m, n);
}