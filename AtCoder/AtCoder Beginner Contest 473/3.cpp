#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<int,MAX_N> counts;
void solve(){   
    ll n,k;
    cin >> n >> k;
    rep(i,0,n,1){
        int classs;
        cin >> classs;
        counts[classs - 1]++;
    }
    partial_sort(counts.begin(), counts.begin()+k, counts.end(), greater<int>());
    int ans = 1;
    int max = counts[0];
    rep(i,1,k,1){
        if(counts[i] < max - 1){
            break;
        }
        ans++;
    }
    cout << ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    //cin >> t;
    while(t--){
        solve();
    }
}