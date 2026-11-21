#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 300005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<vector<int>,3> coords;

void solve(){   
    int n;
    cin >> n;
    string s;
    cin >> s;
    rep(i,0,n,1){
        coords[s.at(i) - 'A'].push_back(i + 1);
    }
    int jUpperBound{n};// j < jUpperBound
    rep(i,0,3,1){
        jUpperBound = min(jUpperBound,(coords[i].empty() ? 0 : coords[i].back()));
    }
    int iLowerBound{0};// i>= iLowerBound
    rep(i,0,3,1){
        iLowerBound = max(iLowerBound,(coords[i].empty()? n : coords[i].front()));
    }
    ll ans{0};
    rep(i,iLowerBound,jUpperBound,1){
        //  how many answers for each i?
        int jLowerBound{i}; // j >= jLowerBound
        rep(j,0,3,1){
            jLowerBound = max(jLowerBound,*upper_bound(coords[j].begin(),coords[j].end(),i));
        }
        ans += max(0,jUpperBound - jLowerBound);
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