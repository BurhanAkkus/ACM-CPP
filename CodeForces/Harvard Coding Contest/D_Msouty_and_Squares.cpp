#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

bool isCorner(ll r, ll c, ll n){
    return (r == 1 || r == n) && (c == 1 || c == n);
}

bool isEdge(ll r, ll c, ll n){
    return (r == 1 || r == n || c == 1 || c == n);
}


void solve(){
    ll l,r;
    cin >> l >> r;
    // there is a square in range.
    if(std::floor(std::sqrt(r)) > std::floor(std::sqrt(l)) || (std::floor(std::sqrt(l)) *  std::floor(std::sqrt(l) == l) )){
        std::cout <<"1\n";
        return;
    }
    ll ans{std::ceil(std::sqrt(r)) * std::ceil(std::sqrt(r)) - r + 1};
    ans = std::min(ans,l+3);
    std::cout << ans << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
