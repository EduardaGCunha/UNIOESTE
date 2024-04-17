#include <stdio.h>

void erase(int arr[]){
    for(int i = 0; i < 5; i++) arr[i] = 12345;
}

void add(int arr[], int n){
    for(int i = 0; i < 5; i++){
        if(arr[i] == 12345){
            arr[i] = n;
            return;
        }
    }
}

void printvet(int arr[], int n, const char *format){
    for(int i = 0; i < 5; i++){
        printf(format, i, arr[i]);
    }
    erase(arr);
    add(arr, n);
}

void printarr(int arr[], const char *format){
    for(int i = 0; i < 5; i++){
        if(arr[i] == 12345) return;
        printf(format, i, arr[i]);
    }
}

int main(){
    int t = 15;
    int par[5], impar[5];
    erase(par);
    erase(impar);
    while(t--){
        int n; scanf("%d", &n);
        if(n%2 == 0){
            if(par[4] == 12345){
                add(par, n);
            }else{
                printvet(par, n, "par[%d] = %d\n");
            }
        }else{
            if(impar[4] == 12345)
                add(impar, n);
            else printvet(impar, n, "impar[%d] = %d\n");
        }
    }
    printarr(impar, "impar[%d] = %d\n");
    printarr(par, "par[%d] = %d\n");
}