#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

struct P{
    ll x, y;
};

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #_VA_ARGS_ << ':'; dbg_out(_VA_ARGS_); }

void read(string file, bool test){
    if (test){
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    else{
        freopen((file+".in").c_str(), "r", stdin);
        freopen((file+".out").c_str(), "w", stdout);
    }
}


signed main(){
    fastio;
    int n;
    cin >> n;
    vector<int> cnt(32);
    for (int i=0; i<n; i++){
        int x;
        cin >> x;
        for (int j=0; j<31; j++){
            if (x & (1<<j)) cnt[j]++;
        }
    }
    for (int i=0; i<n; i++){
        int cur=0;
        for (int j=0; j<31; j++){
            if (cnt[j]) cur |= 1<<j, cnt[j]--;
        }
        cout << cur << ' ';
    }
    cout << '\n';
}