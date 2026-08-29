#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 102
#define MAX_A 102
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<int,MAX_N> counts;
void solve(){   
    ll n;
    cin >> n;
    rep(i,0,n,1){
        int a;
        cin >> a;
        counts[a]++;
    }
    int ans = 0;
    rep(i,1,MAX_A,1){
        ans += (counts[i] %2) * i;
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