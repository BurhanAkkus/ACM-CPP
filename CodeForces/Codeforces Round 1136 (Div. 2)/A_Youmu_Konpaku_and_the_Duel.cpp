#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 30005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<list<int>,MAX_N> prefixSums;

void solve(){   
    ll x;
    cin >> x;
    ll ans{x};
    rep(i,1,700,1){
        auto& currentList{prefixSums[i]};
        // i tane charge varken kac atak yapiyorum?
        auto lowerBound = lower_bound(currentList.begin(),currentList.end(),x);
        if(lowerBound == currentList.end()){
            ans = min(x - currentList.back() + (ll)currentList.size() + i, ans);
        }
        else{
            ans = min(ans, (ll)distance(currentList.begin(), lowerBound) + i + 1);
        }

    }
    ans = min(ans,x);
    cout << ans << "\n";
}

void populateLists(){
    rep(i,1,700,1){
        prefixSums[i].push_back(i + 1);
        rep(j,1,i + 1,1){
            prefixSums[i].push_back(prefixSums[i].back() + i + 1 - j);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    populateLists();
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
}