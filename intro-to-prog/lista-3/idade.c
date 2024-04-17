#include <stdio.h>
int main(){
    double sum = 0, cnt = 0;
    while(1){
        int a; scanf("%d", &a);
        if(a<0) break;
        cnt++;
        sum+= a;
    }

    printf("%.2lf\n", sum/cnt);
}