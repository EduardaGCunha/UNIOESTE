#include <stdio.h>
#include <stdlib.h>

void min(double arr[], int n){
    double mm = 10000.0;
    for(int i = 0; i < n; i++){
        if(arr[i] < mm){
            mm = arr[i];
        }
    }
    printf("%.1lf\n", mm);
}

void max(double arr[], int n){
    double mx = -1.0;
    for(int i = 0; i < n; i++){
        if(arr[i] > mx){
            mx = arr[i];
        }
    }
    printf("%.1lf\n", mx);
}

int main(){
    int t; scanf("%d", &t);
    double arr[t+1];
    for(int i = 0; i < t; i++){
        double n; scanf("%lf", &n);
        arr[i] = n;
    }
    min(arr, t);
    max(arr, t);

}