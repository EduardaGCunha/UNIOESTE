#include <stdio.h>

int main()
{
    int x, y, amigos;
    
    scanf("%d %d", &x, &y);
    
    while(x > 0){
    
        int somaDivisoresX = 0;
        int somaDivisoresY = 0;
        for(int i = 1; i < x; i++){
            if(x % i == 0){
                somaDivisoresX += i;
            }
        }
        for(int j = 1; j < y; j++){
            if(y % j == 0){
                somaDivisoresY += j;
            }
        }
        printf("%d %d", somaDivisoresX, somaDivisoresY);
        if(somaDivisoresX == y && somaDivisoresY == x){
            amigos = 1;
        }else{
            amigos = 0;
        }
        
        printf("#amigo (%d, %d) = %d\n", x, y, amigos);
        
        scanf("%d %d", &x, &y);
    }
    
}