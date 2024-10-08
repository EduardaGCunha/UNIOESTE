#include <bits/stdc++.h>
using namespace std;


int n, m;
int rec(int x){
    if(x == m) return 1;
    if(x > m) return 0;

    return rec(x+1) + rec(x+2) + rec(x+3);
}

int main(){
    cin >> n >> m;
    cout << rec(n) << endl;
}