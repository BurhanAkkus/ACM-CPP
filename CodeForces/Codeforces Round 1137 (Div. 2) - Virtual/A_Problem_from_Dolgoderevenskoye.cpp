#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 300005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<vector<int>,3> coords;

void solve(){   
    ll x;
    cin >> x;
    if(x % 4 == 0 || x % 2 == 1){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
}