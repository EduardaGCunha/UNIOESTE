#include <stdio.h>
#include <string.h>

void obi(char s[]){
    int n = strlen(s);
    if(n > 3){
        printf("%s ", s);
        return;
    }
    if(s[0] == 'O' && s[1] == 'B'){
        printf("OBI ");
    }else if(s[0] == 'U' && s[1] == 'R'){
        printf("URI ");
    }else{
        printf("%s ", s);
    }
}

int main(){
    int n; 
    scanf("%d", &n);
    while(n--){
        char str[10007];
        scanf("%s", str);
        //printf("%s\n", str);
        obi(str);
    }
    printf("\n");
}