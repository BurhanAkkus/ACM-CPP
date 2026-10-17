#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

void solve(){   
    ll n,m;
    cin >> n >> m;
    if( n == 1){
        cout << 0 << endl;
        return;
    }
    if(n == 2){
        cout << 1 << endl;
        cout << "1 1" << endl;
        return;
    }
    cout << (n/2 + n%2) << endl;
    for(int start = 1; start <=(n+1)/2; start++){
        cout << start << " " << (start + n/2 - 1) << endl;
    }
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