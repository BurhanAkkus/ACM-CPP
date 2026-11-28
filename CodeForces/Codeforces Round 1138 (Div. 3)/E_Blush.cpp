#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<ll,35>moves;

void populateMoves(){
    moves[0] = 1;
    rep(i,1,35,1){
        moves[i] = moves[i-1] * 2;
    }
}
void solve(){   
    ll a,x,k;
    cin >> a >> x >> k;
    ll aSave{a};
    int lower{0};
    while(a > (k+1) * (moves[lower] - 1 - x * lower)){
        lower++;
    }
    lower--;
    // lower => butun segmentler lower uzunlugundayken mesafeye sigiyor.
    a -= (k+1) * (moves[lower] - 1 - x * lower);
    int c2{(a - 1)/ (moves[lower] - x)};

    ll ans{(k+1-c2) * x * lower};
    ans += c2 * x * (lower+1);

    cout << ans + aSave << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    populateMoves();
    cin >> t;
    while(t--){
        solve();
    }
}