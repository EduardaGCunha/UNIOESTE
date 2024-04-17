#include <stdio.h>
#include <ctype.h>

void validator(char s[]){
    int i = 0;
    int invalid = 0;
    int min = 0, max = 0, num = 0;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 97 && s[i] <= 122){
            min = 1; 
        }else if(s[i] >= 65 && s[i] <= 95){
            max = 1;
        }else if((s[i] >= 48 && s[i] <= 57)){
            num = 1;
        }else{
            invalid = 1;
        }
    }
    if(min==1 && max==1 && num==1 && invalid == 0 && (i >= 6 && i <= 32)){
        printf("Senha valida.\n");
    }else{
        printf("Senha invalida.\n");
    }
    return;
}

int main(){
    char str[100];
    while(scanf(" %[^\n]", str) != EOF){
        validator(str);
    }
}