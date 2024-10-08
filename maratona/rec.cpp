#include <bits/stdc++.h>
using namespace std;

void rec(int x){
    cout << x << endl;
    if(x == 5) return;
    rec(x+1);
}

int main(){
    rec(1);
    
}