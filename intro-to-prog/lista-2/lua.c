#include <stdio.h>

int main(){
    int n, m; scanf("%d %d", &n, &m);

    if(n >= 0 && m <= 2){
        printf("nova\n");
    }else if(n >= 2 && m <= 96){
        printf("crescente\n");
    }else if(n > 96 && m <= 100){
        printf("cheia\n");
    }else if(n > 96 && m <= 96){
        printf("minguante\n");
    }

}