#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX



void solve(){
    ll n;
    cin >> n;
    rep(i,1,n+1,1){
        if(i % 3 == 0){
            cout << "Fizz\n";
        }
        else{
            cout << i << "\n";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}