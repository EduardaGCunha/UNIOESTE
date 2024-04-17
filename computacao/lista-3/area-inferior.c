#include <stdio.h>

double m[12][12];

void sum(int n){
    double sum = 0;
    for(int j = 11; j > 7; j--){
        for(int i = 9; i > 0; i -= 2){
            sum += m[j][i];
        }
    }
    
}
int main(){
    int n;
    scanf("%d", &n);
    char a; 
    scanf(" %c", &a);
    int j = 0;

}