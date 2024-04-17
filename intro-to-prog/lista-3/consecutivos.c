#include <stdio.h>

int main(){
    int a;
    int sum = 0;
    while(scanf("%d", &a) != EOF){
        if(a < 0) sum+= a;
    }
}