#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 102
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX


array<ll,MAX_N> x{};
vector<ll> answers;
void solve(){
    ll n,d;
    cin >> n >>d;
    rep(i,0,n,1){
        cin >> x[i];
    }
    rep(i,0,n,1){
        ll count = 0;
        ll flag = true;
        rep(j,0,n,1){
            if(abs(x[i] - x[j]) < d){
                if(i != j){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            answers.push_back(i);
        }
    }
    cout << answers.size() << endl;
    for(auto i:answers){
        cout << (i+1) << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}