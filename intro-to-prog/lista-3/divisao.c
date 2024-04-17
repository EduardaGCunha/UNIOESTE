#include <stdio.h>

int main(){
    int n, m; scanf("%d %d", &n, &m);
    if(n>m){
        int t = m;
        m = n;
        n = t;
    }
    for(int i = n; i < m; i++){
        if(i%5==2 || i%5 == 3) printf("%d\n", i);
    }
}