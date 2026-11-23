#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<int,MAX_N> a;
void solve(){   
    ll n, k;
    cin >> n >> k;
    rep(i,0,n,1){
        cin >> a[i];
    }
    int l{0},r{0};
    ll ans{0};
    while(r < n){
        if(a[r] != a[l]){
            l = r;
        }
        if(r - l >= n - k){
            ans++;
        }
        r++;
    }
    cout << ans << "\n";
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