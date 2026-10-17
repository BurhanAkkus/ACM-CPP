#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 102
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<ll,MAX_N> happiness;
void solve(){   
    ll n,v;
    cin >> n >> v;
    rep(i,0,n,1){
        cin >> happiness[i];
    }
    ll ans = 0;
    rep(i,0,n,1){
        rep(j,i+1,n,1){
            rep(l,j+1,n,1){
                if(i + j + l + 3 <= v){
                    ans = max(ans,happiness[i] + happiness[j] + happiness[l]);
                }
            }
        }
    }
    cout << ans;
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