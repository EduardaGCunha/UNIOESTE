#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400;
int n, m;
int arr[MAXN][MAXN];
bool check(int i, int j, int a, int b){
    for(int x= i; x <= a; x++){
        for(int y = j; y <= b; y++){
            if(arr[x][y] != 1) return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int a = i; a < n; a++){
                for(int b = j; b < m; b++){
                    if(check(i, j, a, b)){
                        int area = (i-a+1)*(j-b+1);
                        //cout << area << endl;
                        ans = max(ans, (a- i + 1)*(b-j+1));
                    }
                }
            }
        }
    }

    cout << ans << endl;
}