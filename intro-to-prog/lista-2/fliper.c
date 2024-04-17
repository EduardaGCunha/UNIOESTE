#include <stdio.h>

int main(){
    int a, b; 
    scanf("%d %d", &a, &b);


    char result = 'A';
    a != 0 ? (b == 0? (result = 'B'): (result = 'A')): (result = 'C');
    printf("%c\n", result);
}