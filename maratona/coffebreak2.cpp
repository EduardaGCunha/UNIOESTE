#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 401;
int matriz[MAXN][MAXN];

int check(int a, int b, int x, int y){
    //fazer outro for q vai checar se tudo tem 1

}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matriz[i][j];
        }
    }

    int ans = 0; 
    for(int a = 0; a < n; a++){
        for(int b = 0; b < m; b++){
            for(int x = a; x < n; x++){
                for(int y = b; y < m; y++){
                    if(check(a, b, x, y)){
                        //calcular o tamanho da matriz
                        //(x-a)*(b-y)
                        //max(ans, (x-a)*(b-y))
                    }
                }
            }
        }
    }

}