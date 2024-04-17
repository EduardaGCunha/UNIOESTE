#include <stdio.h>

int main(){
    char val;
    while(scanf("%c", &val) != EOF){
        if(val >= 97 && val <= 122){
            if(val < 109){
                val = 122 - (val - 97);
            }else if(val > 109){
                val = 97 + (val - 122);
            }
        }else if(val >= 65 && val <= 90){
            if(val < 77){
                val = 90 - (val - 65);
            }else if(val > 77){
                val = 90 - (val - 65);
            } 
        }
        printf("%c", val);
    }
}