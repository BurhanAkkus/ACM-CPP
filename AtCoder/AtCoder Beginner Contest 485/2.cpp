#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 30005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

void solve(){   
    ll n,m;
    cin >> n >> m;
    bool flowMap[n][m];
    rep(i,0,n,1){
        rep(j,0,m,1){
            char c;
            cin >> c;
            flowMap[i][j] = (c == 'o');
        }
    }
    // check faucets!
    rep(i,0,n,1){
        bool allClogged = true;
        rep(j,0,m,1){
            if(flowMap[i][j]){
                allClogged = false;
                break;
            }
        }
        if(allClogged){
            cout<< "Faucet " << (i + 1);
            return;
        }
    }

    rep(j,0,m,1){
        bool allClogged = true;
        rep(i,0,n,1){
            if(flowMap[i][j]){
                allClogged = false;
                break;
            }
        }
        if(allClogged){
            cout<< "Drain " << (j + 1);
            return;
        }
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