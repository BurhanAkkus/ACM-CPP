#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX



void solve(){
    char c;
    cin >> c;
    if(c == 'B'){
        cout << "Y";
    }
    else if(c == 'Y'){
        cout << "R";
    }
    else{
        cout << "B";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}