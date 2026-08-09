#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 500005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX


array<int,MAX_N> a;
vector<int> nonZeroes,nonZeroes2;
void solve(){
    ll n,q;
    cin >> n >> q;
    ll currentXor = 0;
    rep(i,0,q,1){
        ll type;
        cin >> type;
        if(type == 1){
            ll index;
            cin >> index;
            a[index]++;
            if(a[index] == 1){
                nonZeroes.push_back(index);
            }
            currentXor ^= a[index] - 1;
            currentXor ^= a[index];
            cout << currentXor << "\n";
        }
        else{
            nonZeroes2.clear();
            for(auto nonZero: nonZeroes){ 
                currentXor ^= a[nonZero];
                currentXor ^= a[nonZero] - 1;
                a[nonZero]--;
                if(a[nonZero] > 0){
                    nonZeroes2.push_back(nonZero);
                }
            }
            cout << currentXor << "\n";
            nonZeroes = nonZeroes2;
        }
    }   

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}