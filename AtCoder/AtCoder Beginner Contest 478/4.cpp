#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<vector<pair<int,int>>,MAX_N> ranges_;
array<int,MAX_N> ans;
void solve(){   
    ll n,q;
    cin >> n >> q;
    rep(i,0,q,1){
        int l,r,x;
        cin >> l >> r >> x;
        ranges_[x].emplace_back(pair{l,r});
    }
    rep(i,0,q + 1,1){
        if(ranges_[i].size() == 0){
            continue;
        }
        sort(ranges_[i].begin(),ranges_[i].end());
        // fix overlaps
        vector<pair<int,int>> newRanges;
        rep(j,0,ranges_[i].size(),1){
            if(newRanges.size() != 0 && newRanges.back().second >= ranges_[i][j].first){
                newRanges.back().second = max(newRanges.back().second,ranges_[i][j].second);
            }
            else{
                newRanges.emplace_back(ranges_[i][j]);
            }
        }
        ranges_[i] = newRanges;
    }
    rep(i,1,q + 1,1){
        if(ranges_[i].size() == 0){
            continue;
        }
        for(auto& [l,r]:ranges_[i]){
            ans[l] += 1;
            ans[r + 1] -= 1;
        }
    }
    ll c = 0;
    rep(i,1,n + 1,1){
        c+=ans[i];
        cout << c << " ";
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