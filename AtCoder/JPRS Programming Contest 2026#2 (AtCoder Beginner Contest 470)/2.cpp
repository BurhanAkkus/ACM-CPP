#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 102
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX



array<ll,MAX_N> colors{};
void solve(){
    ll n;
    cin >> n;
    ll maxim = -1;
    rep(i,0,n,1){
        ll c;
        cin >> c;
        colors[c]++;
        maxim = max(maxim,colors[c]);
    }
    cout << n - maxim;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}