#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<ll,MAX_N> a;

int getBit(ll n, int bit){
    return (n >> bit) & 1;
}
void solve(){   
    ll n;
    cin >> n;
    ll orSum{0};
    ll andSum{~0LL};// hepsi 1 olan sayi. 
    rep(i,0,n,1){
        cin >> a[i];
        orSum |= a[i];
        andSum &= a[i];
    }

    for(int i = 63; i >= 0; i--){
        if(getBit(orSum,i) != getBit(andSum,i)){
            for(int j = i; j >= 0; j--){
                orSum |= (1LL << j);
            }
            break;
        }
    }
    cout << orSum << endl;
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