#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

void solve(){   
    ll n;
    ll a;
    cin >> n;
    ll sum{0};
    ll evenCount{0};
    rep(i,0,n,1){
        cin >> a;
        sum += a;
        evenCount += 1 - (a % 2);
    }
    // first element is taken no matter what.
    if(n == 1){
        cout << "Moggity\n";
        return;
    }
    // take all.
    if(sum %2 == 0){
        cout << "Moggity\n";
        return;
    }
    // 1 even 1 odd. cant take all. must leave 1.
    if(n == 2){
        cout << "Larpity\n";
        return;
    }
    // sum is odd, n > 2
    if(evenCount > 0){
        cout << "Moggity\n";
        return;
    }
    // sum is odd, all of them are odd numbers.
    if(n == 3){
        cout << "Larpity\n";
        return;
    }
    cout << "Moggity\n";
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