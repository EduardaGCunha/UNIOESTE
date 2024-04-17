#include <stdio.h>

int main(){
    char c; scanf("%c", &c);
    int result = 0;
    if(c - 97 >= 0 && c - 97 < 26){
        result = 1;
    }else if(c - 65 >= 0 && c - 65 < 26){
        result = 1;
    }
    printf("Eh uma letra? %d\n", result);
}