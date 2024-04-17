#include <stdio.h>

int main(){
    int n, m; scanf("%d %d", &n, &m);
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        cnt++;
        if(cnt == n){
            printf("%d\n", i);
            cnt = 0;
        }else{
            printf("%d ", i);
        }
    }
}