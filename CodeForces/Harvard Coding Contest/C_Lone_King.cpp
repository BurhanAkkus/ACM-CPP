#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

bool isCorner(ll r, ll c, ll n){
    return (r == 1 || r == n) && (c == 1 || c == n);
}

bool isEdge(ll r, ll c, ll n){
    return (r == 1 || r == n || c == 1 || c == n);
}


void solve(){
    ll n,r,c;
    cin >> n >> r >> c;
    //std::cout << n << " " << r << " " << c << "\n";
    if(n == 1){std::cout << "0\n";return;}
    if(n == 2){std::cout << "-1\n"; return;}
    if(n == 3){
        if(r == 2 && c == 2){std::cout << "-1\n"; return;}
    }
    if(isCorner(r,c,n)){
        std::cout << "1\n";
        return;
    }
    if(isEdge(r,c,n)){
        std::cout << "2\n";
        return;
    }
    if(n == 4){
        std::cout<<"3\n";
        return;
    }
    std::cout<<"2\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
