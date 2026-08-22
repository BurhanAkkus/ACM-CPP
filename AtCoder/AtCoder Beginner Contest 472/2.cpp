#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;
#define MAX_N 102
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX

array<ll,MAX_N> a;
void solve(){
    ll n;
    cin >> n;
    int sum = 0;

    rep(i,0,n,1){
        cin >> a[i];
        sum += a[i];
    }
    int runningSum = 0;
    int minim = INT_MAX;
    rep(i,0,n,1){
        runningSum += a[i];
        minim = min(minim,abs(sum-runningSum - runningSum));
    }
    cout << minim;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin >> t;
    while(t--){   
        solve();
    }
}