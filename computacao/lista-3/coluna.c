#include <stdio.h> 

double m[12][12];

void sum(int j){
    double sum = 0;
    for(int i = 0; i < 12; i++){
        sum += m[i][j];
    }
    printf("%.1lf\n", sum);
}

void media(int j){
    double sum = 0;
    for(int i = 0; i < 12; i++){
        sum += m[i][j];
    }
    printf("%.1lf\n", sum/12);
}

int main(){
    int n; 
    scanf("%d", &n);
    char a; 
    scanf(" %c", &a);
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            double b; 
            scanf("%lf", &b);
            m[i][j] = b;
        }
    }

    if(a=='S') sum(n);
    else media(n);
}