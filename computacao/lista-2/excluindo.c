#include <stdio.h>

void bubblesort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    int arr[n+1];
    for(int i = 0; i < n; i++){
        int a; scanf("%d", &a);
        arr[i] = a;
    }
    bubblesort(arr, n);
     for (int i = 1; i <= n; i++) {
        if(arr[i] != arr[i-1])printf("%d\n", arr[i-1]);
    }
}