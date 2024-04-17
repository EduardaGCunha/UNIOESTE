#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cripto(char s[]){
    char aux;
    int n = strlen(s);
        for(int j = 0; j < n; ++j){
            if(isalpha(s[j])){
                s[j] += 3;
            }
        }

        for(int j = 0; j < n/2; ++j){
            aux = s[j];
            s[j] = s[n - 1 - j];
            s[n - 1 - j] = aux;
        }
        for(int j = n/2; j < n; ++j){
            --s[j];
        }

        printf("%s\n", s);

}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        char str[1007];
        scanf(" %[^\n]", str);
        cripto(str);
    }
}