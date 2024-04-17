#include <stdio.h>
#include <stdbool.h>

void lervetor(int arr[], int n){
    for(int i = 0; i < n; i++){
        int a; 
        scanf("%d", &a);
        arr[i] = a;
    }
}

bool check(int arr[], int n){
    int e = 0;
    for(int i = 0; i < n; i++){
        if (i > 1 && arr[i] % 2 != arr[i - 2] % 2)
		e = 1;
    }

    if(e){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
}

int main(){
    int t; 
    scanf("%d", &t);
    while(t--){
        int n; 
        scanf("%d", &n);
        int arr[n];
        lervetor(arr, n);
        check(arr, n);
    }
}