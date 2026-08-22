#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200002
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX

vector<ll> xIndices;

// returns the first element i such that array[i] > element
ll upper_bound_custom(vector<ll>& array, ll n, ll element){
    ll l = 0;
    ll r = n;
    while(l < r){
        ll mid = l + (r - l) /2; // rounds down.
        if(array[mid] <= element) {l = mid + 1;} // shrinks the interval [l,r) 
        else{
            r = mid; // shrinks the interval.
        }
    }
    return l;
}
array<ll,MAX_N> a;
array<bool,MAX_N> ate;
void solve(){
    ll n,m,k;
    cin >> n >> m >> k;
    rep(i,0,n,1){
        cin >> a[i];
        ate[i] = false;
    }
    ll runningSum = 0;
    rep(i,0,n,1){
        if(runningSum + a[i] <= k){
            runningSum += a[i];
            ate[i] = true;
            cout << "Yes\n";
        }
        else{
            cout <<"No\n";
        }
        if(i-m+1 >=0 && ate[i-m+1]){
            runningSum -= a[i-m+1];
        } 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin >> t;
    while(t--){   
        solve();
    }
}