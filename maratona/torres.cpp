#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n][n];
    vector<int> linhas(n);
    vector<int> colunas(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            linhas[i] += arr[i][j];
            colunas[j] += arr[i][j];
        } 
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res = max(res, linhas[i] + colunas[j] - 2*arr[i][j]);
        }
    }
    cout << res << endl;
}