#include <stdio.h>

#define MAXN 1000

int calc(int x, int y, int matrix[][MAXN]){
    return matrix[x][y] + matrix[x][y+1] + matrix[x+1][y] + matrix[x+1][y+1];
}

void lermat(int n, int matrix[][MAXN]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main(){
    int n; 
    scanf("%d", &n);
    int mat[MAXN][MAXN];
    lermat(n, mat);
    int prev = calc(0, 0, mat);
    for(int i = 0; i < n-1; i+=2){
        for(int j = 0; j < n - 1; j+=2){
            int current = calc(i, j, mat);
            if(current != prev){
                printf("NAO\n");
                return 0;
            }
        }
    }
    printf("SIM - %d\n", prev);
    return 0;
}
