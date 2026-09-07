#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll x;
    cin >> x;
    if (x == 0){
        cout << "A";
        return;
    }

    const int LIM = 50;
    ll bestLen = LLONG_MAX;
    int k_ = 0, bk_ = 0, l_ = 1, bl_ = 0;

    for (int k = 0; k < LIM; k++){
        for (int bk = 0; bk < LIM; bk++){
            ll K = k + bk;
            for (int l = 1; l < LIM; l++){
                for (int bl = 0; bl < LIM; bl++){
                    ll L = l + bl;
                    ll val = k + K * L;
                    if (val != x) continue;
                    ll length = 2*k + 2*l + 2*bk + 2*bl + 1;
                    if (length < bestLen){
                        bestLen = length;
                        k_ = k; bk_ = bk; l_ = l; bl_ = bl;
                    }
                }
            }
        }
    }

    string s;
    // k
    for (int i = 0; i < k_; i++)
    { cout << "AR";}
    cout<< "CR";
    for (int i = 0; i < bk_; i++) {cout<<"AR";}
    cout<<"C";
    for (int i = 0; i < bl_ + l_ - 1; i++) cout<<"RC";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while (t--){
        solve();
    }
}
