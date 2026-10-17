#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<int,MAX_N> a,b;
void solve(){   
    ll n,k;
    cin >> n >> k;
    rep(i,0,n,1){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.begin() + n);
    ll minim = n;
    ll maxim = -1;
    rep(i,0,n,1){
        if(a[i] != b[i]){
            minim = min(minim,i);
            maxim = max(maxim,i);
        }
    }     

    cout << ((maxim - minim) < k? "Yes" : "No");
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