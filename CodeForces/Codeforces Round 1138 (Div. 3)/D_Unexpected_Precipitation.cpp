#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<array<ll,2>,MAX_N> dp;// [i][0] = what is the maximum score when Sunny is on left coridor from i to n
                            // [i][1] = what is the minimum score when Aubrey is on left coridor from i to n
array<ll,MAX_N> x,y;
void solve(){   
    ll n;
    cin >>n;
    rep(i,0,n,1){
        cin >> x[i];
    }
    rep(i,0,n,1){
        cin >> y[i];
    }
    dp[n - 1][0] = max(x[n-1]- y[n-1],0ll);
    dp[n - 1][1] = min(y[n-1]- x[n-1],0ll);
    for(int i = n - 2; i >= 0; i--){
        dp[i][0] = max(
            // first operation
            x[i] - y[i] + dp[i + 1][0],
            // second operation
            dp[i+1][1]
        );
        dp[i][1] = min(
            // first operation
            y[i] - x[i] + dp[i+1][1],
            // second operation
            dp[i+1][0]
        );
    }
    if(dp[0][0] == 0){
        cout << "Draw\n";
        return;
    }
    if(dp[0][0] > 0){
        cout << "Sunny\n";
        return;
    }
    cout << "Aubrey\n";
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