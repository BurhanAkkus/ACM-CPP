#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 400005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX

array<ll,MAX_N> counts;
void solve(){
    ll q;
    cin >> q;
    string s,t;
    cin >> s >> t;
    int tSize = t.length();
    if(tSize > s.size()){
        rep(i,0,q,1){
            ll l,r;
            cin >> l >> r;
            cout << "No\n";
        }
        return;
    }
    counts[0] = (s.substr(0,tSize).compare(t) == 0);
    rep(i,1,s.size()-tSize+1,1){
        counts[i] = counts[i-1] + (s.substr(i,tSize).compare(t) == 0);
    }
    rep(i,s.size()-tSize + 1,s.size(),1){
        counts[i] = counts[i-1];
    }
    rep(i,0,q,1){
        ll l,r;
        cin >> l >> r;
        l--;r--;
        if(l + tSize - 1 > r){
            cout << "No\n";
            continue;
        }
        ll leftCount = (l > 0?counts[l-1] : 0);
        ll rightCount = counts[r - tSize + 1];
        cout << (rightCount - leftCount > 0 ? "Yes\n" : "No\n"); 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}