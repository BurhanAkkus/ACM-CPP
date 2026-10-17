#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

vector<ll> plusV,minusV,plusPrefixSum,minusPrefixSum;
void solve(){   
    plusV.clear();
    minusV.clear();
    plusPrefixSum.clear();
    minusPrefixSum.clear();
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    char prev = '(';
    ll consec = 0;
    rep(i,0,n,1){
        if(prev == s.at(i)){
            consec++;
        }
        else{
            if(prev == '('){
                plusV.push_back(consec);
            }
            else{
                minusV.push_back(consec);
            }
            consec = 1;
            prev = s.at(i);
        }
    }
    minusV.push_back(consec);
    plusPrefixSum.push_back(0);
    minusPrefixSum.push_back(0);
    minusPrefixSum.push_back(0);
    for(ll plusP:plusV){
        plusPrefixSum.push_back(plusP + plusPrefixSum.back());
    }
    plusPrefixSum.push_back(plusPrefixSum.back());
    for(ll minusP:minusV){
        minusPrefixSum.push_back(minusP + minusPrefixSum.back());
    }
    ll ans = 0;
    for(int i = 1; i < plusPrefixSum.size(); i++){
        z
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