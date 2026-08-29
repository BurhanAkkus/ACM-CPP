#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<int,MAX_N> a;
void solve(){   
    ll n,k;
    cin >> n >> k;
    rep(i,0,n,1){
        cin >> a[i];
    }
    ll ans = 0;
    int l = 0;
    ll sum = 0;
    set<ll> sums;
    sums.insert(0);
    while(l < n){
        sum+= a[l];
        if(sums.contains(sum % k)){
            ans++;
            sum = 0;
            sums.clear();
            sums.insert(0);
        }
        else{
            sums.insert(sum % k);
        }
        l++;
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