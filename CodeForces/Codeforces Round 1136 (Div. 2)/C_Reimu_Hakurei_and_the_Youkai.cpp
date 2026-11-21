#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 30005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

vector<ll> a;
void solve(){   
    a.clear();
    ll n,x;
    cin >> n >> x;
    rep(i,0,n,1){
        ll c;
        cin >> c;
        a.push_back(c);
    }
    sort(a.begin(), a.end());
    a.pop_back();
    ll cost{0};
    ll atakSayisi{0};
    auto olcekler{upper_bound(a.begin(),a.end(), atakSayisi * x + x)};
    int olenler = 0;
    while(olcekler != a.end()){
        // someone will die to my next attack.
        if(distance(a.begin(),olcekler) > olenler){
            atakSayisi++;
            olenler++;
        }
        // noone will die to my next attack.
        else{
            // how many attacks until the next one dies?
            ll numberOfAttacksUntilSomeoneDies{(*olcekler - atakSayisi * x + x - 1) / x};
            cost += numberOfAttacksUntilSomeoneDies - 1;
            atakSayisi += numberOfAttacksUntilSomeoneDies - 1;
        }
        olcekler = upper_bound(a.begin(),a.end(),atakSayisi * x + x);
    }

    cout << cost << "\n";
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