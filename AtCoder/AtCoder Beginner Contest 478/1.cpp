#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 30005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

void solve(){   
    ll n,m;
    cin >> n >> m;
    ll mod = m % n;
    rep(i,1,n + 1,1){
        cout << m / n + (i <= mod) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}