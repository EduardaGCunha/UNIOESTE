#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n; cin >> n;
    vector<tuple<int, int, int>> arr; 

    int sum = 0, mini = 1e9+1, maxi = 0;

    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        if(a == 1){
            sum += b;
            mini = min(mini, b);
            maxi = max(maxi, b);
        }else if(a == 2){
            cout << get<2>(arr[b-1]) << endl;
        }else if(a == 3){
            cout << get<1>(arr[b-1]) << endl;
        }else  cout << get<0>(arr[b-1]) << endl;

        arr.push_back({sum, mini, maxi});
    }
}