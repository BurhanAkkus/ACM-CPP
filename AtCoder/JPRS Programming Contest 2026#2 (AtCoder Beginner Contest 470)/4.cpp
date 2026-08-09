#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 500005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX


array<int,MAX_N> p1,p2;
void solve(){
    bool answerIsP1 = true;
    ll n,q;
    cin >> n >> q;
    rep(i,1,n+1,1){
        cin >> p1[i];
        p2[p1[i]] = i;
    }
    rep(i,0,q,1){
        ll type;
        cin >> type;
        if(type == 1){
            ll x,y;
            cin >> x >> y;
            if(answerIsP1){
                ll temp = p2[p1[x]];
                p2[p1[x]] = p2[p1[y]];
                p2[p1[y]] = temp;
                temp = p1[x];
                p1[x] = p1[y];
                p1[y] = temp;
            }
            else{
                ll temp = p1[p2[x]];
                p1[p2[x]] = p1[p2[y]];
                p1[p2[y]] = temp;
                temp = p2[x];
                p2[x] = p2[y];
                p2[y] = temp;
            }
        }
        else{
            answerIsP1 = !answerIsP1;
        }
    }
    if(answerIsP1){
        rep(i,1,n+1,1){
            cout << p1[i] << " ";
        }
        return;
    }
    else{
        
        rep(i,1,n+1,1){
            cout << p2[i] << " ";
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}