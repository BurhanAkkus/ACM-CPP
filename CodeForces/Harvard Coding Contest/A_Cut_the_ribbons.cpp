#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

const long long MAX_N = 200000;

std::array<ll,MAX_N+2> a;
void solve(){
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> a[i];
    }
    ll gcd = a[0];
    rep(i,0,n,1){
        gcd = std::gcd(gcd,a[i]);
    }
    std::cout << gcd << "\n";
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
