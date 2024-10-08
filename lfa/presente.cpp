#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c; cin >> n >> c;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    int i;
    for(i = 0; i < n; i++){
        if(c < arr[i]) break;
        c -= arr[i];
    }

    cout << i << endl;
}