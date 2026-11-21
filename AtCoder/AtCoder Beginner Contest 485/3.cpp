#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 300005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<int,MAX_N> colors;


void solve(){   
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> colors[i];
        colors[i]--;
    }
    int start{0};
    rep(i,1,n,1){
        if(colors[i] != colors[i - 1]){
            // everything from start to i-1 is same color.
            rep(j,start,i,1){
                ll ans = MAX_N;
                if(start > 0){
                    ans = min(ans, j - start + 1);
                }
                ans = min(ans,i - j);
                cout << ans << " ";
            }
            start = i;
        }
    }
    rep(j,start,n,1){
        ll ans = MAX_N;
        if(start > 0){
            ans = min(ans, j - start + 1);
        }
        cout << ans << " ";
    }

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