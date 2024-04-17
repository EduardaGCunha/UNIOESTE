#include <stdio.h>
#include <stdbool.h>

bool impar(int arr[], int n){
    for(int i = 0; i < n; i+=2){
        arr[i] = arr[i] + 1;
    }
    bool res = true, res2 = true;
    for(int i = 0; i < n; i++){
        if(arr[i]%2 != 0) res = false;
        if(arr[i]%2 != 1) res = false;
    }
    if(res || res2) return true;
    else return false;
}

bool par(int arr[], int n){
    for(int i = 1; i < n-1; i+=2){
        arr[i]++;
    }
    bool res = true, res2 = true;
    for(int i = 0; i < n; i++){
        if(arr[i]%2 != 0) res = false;
        if(arr[i]%2 != 1) res2 = false;
    }
    if(res || res2) return true;
    else return false;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        int arr[n+1];
        int cnt_p = 0, cnt_i = 0;
        for(int i = 0; i < n; i++){
            int a; scanf("%d", &a);
            arr[i] = a;
            if(a%2 == 0) cnt_p++;
            else cnt_i++;

        }
        if(cnt_p == n || cnt_i == n){
            printf("YES\n");
            continue;
        }
        bool res1 = impar(arr, n);
        bool res2 = par(arr, n);
        if(res1 || res2){
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }

    
}