#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 20;
int arr[MAXN];
int n;

int apple(int a, int b, int i){
    if(i == n) return abs(a-b);

    return min(apple(a+arr[i], b, i+1), apple(a, b+arr[i], i+1));
}

signed main(){
    cin >> n;
    for(int i = 0; i< n; i++) cin >> arr[i];

    cout << apple(0, 0, 0) << endl;
}