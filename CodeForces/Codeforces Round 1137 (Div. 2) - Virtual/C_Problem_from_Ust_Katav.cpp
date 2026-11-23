#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<int,MAX_N> a,soldakiKucuk,sagdakiKucuk;
void solve(){   
    int n;
    cin >> n;
    rep(i,0,n,1){
        cin >> a[i];
        soldakiKucuk[i] = -1;
        sagdakiKucuk[i] = n;
    }
    stack<int> kucukler;
    rep(i,0,n,1){
        while(!kucukler.empty() && a[kucukler.top()] > a[i]){
            sagdakiKucuk[kucukler.top()] = i;
            kucukler.pop();
            }
        if(!kucukler.empty()){
            soldakiKucuk[i] = kucukler.top();
        }
        kucukler.push(i);
    }
    if(n == 1) {cout << 1 << "\n"; return;}
    ll ans{0};
    rep(i,0,n,1){
        if(soldakiKucuk[i] == i-1 && sagdakiKucuk[i] == i + 1){
            ans++;
        } 
        else if(soldakiKucuk[i] != i-1 && sagdakiKucuk[i] != i + 1){
            ans += 2;
        }
        else if(soldakiKucuk[i] == i - 1){
            ans += sagdakiKucuk[i] - i;
        }
        else if(sagdakiKucuk[i] == i + 1){
            ans += i - soldakiKucuk[i];
        }
    }
    
    cout << ans << "\n";
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