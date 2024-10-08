#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2*(1e5); 
int arr[MAXN+1];

signed main(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        arr[i] += arr[i-1] + a;
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << arr[b] - arr[a-1] << endl;
    }


}