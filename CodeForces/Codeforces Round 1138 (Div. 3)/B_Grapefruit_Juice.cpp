#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<ll,MAX_N> a;

void solve(){   
    ll n,k,p;
    cin >> n >> k >> p;
    rep(i,0,n,1){
        cin >> a[i];
    }
    sort(a.begin(),a.begin() + n);
    int start{0};
    while(start * k <= n - k){    
        ll tempSum{0};
        rep(j,0,k,1){
            tempSum += a[start * k +j];
        }
        if(tempSum >= p){
            break;
        }
        start++;
    }
    ll ans{start * p};
    rep(i,start * k,n,1){
        ans += a[i];
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