#include <bits/stdc++.h>
using namespace std;

int s, e;

int rec(int x){
    if(x > e) return 0;
    if(x == e) return 1;
    return rec(x+1) + rec(x+2) + rec(x+3);
}


int main(){
    cin >> s >> e;

    cout << rec(s) << endl;
}