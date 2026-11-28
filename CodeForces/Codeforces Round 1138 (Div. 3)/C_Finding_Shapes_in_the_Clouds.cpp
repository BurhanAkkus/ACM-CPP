#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<ll,MAX_N> a;

void solve(){   
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(n % 2 == 1){
        cout << "NO\n";
        return;
    }
    bool flag{true};
    rep(i,1,n,1){
        if(s[i] == s[i-1]){
            flag = false;
            break;
        }
    }
    if(!flag){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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