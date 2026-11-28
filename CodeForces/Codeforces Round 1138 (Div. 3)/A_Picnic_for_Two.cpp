#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 300005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<vector<int>,3> coords;

void solve(){   
    ll l,a,b;
    cin >> l >> a >> b;
    ll ans{0};
    ll i{0};
    set<int> blue;
    while(blue.find(i) == blue.end()){
        blue.insert(i);
        i += a;
        i %= l;
    }
    i = 0;
    set<int> straw;
    while(straw.find(i) == straw.end()){
        straw.insert(i);
        i += b;
        i %= l;
    }
    for(auto bl : blue){
        if(straw.find(bl) != straw.end()){
            ans++;
        }
    }
    cout << ans << "\n";
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