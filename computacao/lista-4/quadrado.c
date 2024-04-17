#include <stdio.h>

#define MAXN 1000

void lermat(int mat[][MAXN], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

int linha(int n, int mat[][MAXN]){
    int prev = 0;
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < n; j++){
            prev += mat[i][j];
        }
    }
    for(int i = 1; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += mat[i][j];
        }
        if(sum != prev){
            return -1;
        }
        prev = sum; 
    }
    return prev;
}

int coluna(int n, int mat[][MAXN]){
    int prev = 0;
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < n; j++){
            prev += mat[j][i];
        }
    }

    for(int i = 1; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += mat[j][i];
        }
        if(sum != prev){
            return -1;
        }
        prev = sum; 
    }
    return prev;
}

int diagonal(int n, int mat[][MAXN]){
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += mat[i][i];
    }
    for(int j = n-1, i = 0; j > 0; j--, i++){
        sum2 += mat[j][i];
    }
    if(sum1 != sum2){
        return -1;
    }
    return sum1;
}

int main(){
    int n; 
    scanf("%d", &n);
    int matrix[MAXN][MAXN];
    lermat(matrix, n);
    int l = linha(n, matrix);
    int c = coluna(n, matrix);
    int d = diagonal(n, matrix);
    if(l != c && l != d && c != d){
        printf("-1\n");
    }else{
        printf("%d\n", l);
    }
}