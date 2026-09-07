#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 30
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<ll,MAX_N> a;
void solve(){   
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> a[i];
    }
    ll ans = 0;
    // get the last element to be 0.
    for(int i = n-1; i >= 0; i--){
        
    }

    for(int i = n-1; i >= 0;i--){
        if(a[i] == 0){
            arkadaSifirVar = true;
            continue;
        }
        ll geciciAns = 0;
        if(!arkadaSifirVar){geciciAns++;}
        else{geciciAns += a[i];}
        ll c = 1;
        ll kullandigimExtra = 0;
        for(int j = i ; j >= 0; j--,c*=2){
            if(a[j] < c){cout << "-1"<< endl;return;}
            if(a[j] > kullandigimExtra + c){kullandigimExtra = max(kullandigimExtra, geciciAns);}
            a[j] -= c;
        }
        arkadaSifirVar = true;
        ans += geciciAns;
    }
    cout << ans << endl;
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