#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    int arr[n+1];
    int m = 1e9;
    int ans = -1;
    for(int i = 0; i < n; i++){
        int a; scanf("%d", &a);
        if(a < m){
            m = a;
            ans = i;
        }
    }

    printf("Menor valor: %d\n", m);
    printf("Posicao: %d\n", ans);
}