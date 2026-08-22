#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 30005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<ll,MAX_N> x,y;
array<ll,MAX_N> a,tx,ty;
array<ll,MAX_N> prefixSumCx,prefixSumCy,prefixSumA;
void solve(){
    ll n,q;
    cin >> n >> q;
    rep(i,0,n,1){
        cin >> x[i] >> y[i];
    }
    rep(i,0,n,1){
        a[i] = (x[i] * y[(i+1) % n] - x[(i+1) % n] * y[i]);
        tx[i] = x[i] + x[(i+1) %n];
        ty[i] = y[i] + y[(i+1) %n];
    }
    prefixSumCx[0] = a[0] * tx[0];
    prefixSumCy[0] = a[0] * ty[0];
    prefixSumA[0] = a[0];
    rep(i,1,n,1){
        prefixSumCx[i] = prefixSumCx[i-1] + tx[i] * a[i];
        prefixSumCy[i] = prefixSumCy[i-1] + ty[i] * a[i];
        prefixSumA[i] = prefixSumA[i-1] + a[i];
    }
    rep(i,0,q,1){
        int u,v;
        cin >> u >> v;
        u--;v--;
        ll bonusA, bonusCx,bonusCy,disKenarlarA,disKenarlarCx,disKenarlarCy;
        if(v > u){
            // direction matters?
            bonusA = x[v] * y[u] - x[u] * y[v];
            bonusCx = bonusA * (x[u] + x[v]);
            bonusCy = bonusA * (y[u] + y[v]);
            disKenarlarA = prefixSumA[v - 1] - (u > 0? prefixSumA[u - 1] : 0);
            disKenarlarCx = prefixSumCx[v - 1] - (u > 0? prefixSumCx[u - 1] : 0);
            disKenarlarCy = prefixSumCy[v - 1] - ( u > 0? prefixSumCy[u - 1] : 0);
        }
        if(u > v){
            bonusA = x[v] * y[u] - x[u] * y[v];
            bonusCx = bonusA * (x[u] + x[v]);
            bonusCy = bonusA * (y[u] + y[v]);
            disKenarlarA = prefixSumA[n - 1] - prefixSumA[u - 1] + (v > 0? prefixSumA[v - 1] : 0);
            disKenarlarCx = prefixSumCx[n - 1] - prefixSumCx[u - 1] + (v > 0? prefixSumCx[v-1] : 0);
            disKenarlarCy = prefixSumCy[n - 1] - prefixSumCy[u - 1] + (v > 0? prefixSumCy[v-1] : 0);
        }

        double Area = (bonusA + disKenarlarA) / 2.0;
        double cx = (disKenarlarCx + bonusCx) / (6 * Area);
        double cy = (disKenarlarCy + bonusCy) / (6 * Area);
        cout << fixed << setprecision(14) << cx << " " << cy << "\n";
    }   



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