#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

void solve(){   
    ll n;
    string s;
    cin >> n;
    cin >> s;
    ll minim = n;
    ll maxim = 0;
    ll count = 0;
    rep(i,0,n,1){
        if(s.at(i) == '1'){
            minim = min(minim,i);
            maxim = max(maxim,i);
            count++;
        }
    }
    if(count == 1){
        cout << 0 << endl;
        return;
    }
    if(count == 2){
        cout << 1 << endl;
        return;
    }
    cout << maxim - minim << endl;
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