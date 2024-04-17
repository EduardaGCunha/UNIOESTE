#include <stdio.h>

int main(){
    int p, j1, j2, r, a; scanf("%d %d %d %d %d", &p, &j1, &j2, &r, &a);
    int sum = j1 + j2;
    if(a == 0 && r == 0){
        if(p != 0){
            sum % 2 == 0? printf("Jogador 1 ganha!\n") : printf("Jogador 2 ganha!\n");
        } 
    }else if(a == 1 && r == 0 || a == 0 && r == 1){
        printf("Jogador 1 ganha!\n");
    }else if(a == 1 && r == 1){
        printf("Jogador 2 ganha!\n");
    }
}