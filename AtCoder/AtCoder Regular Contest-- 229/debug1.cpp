#include <bits/stdc++.h>
using namespace std;
#define ll long long
array<ll,700> saflar;
array<int,700> parent,kcarpani;
void direktYazdir(int x, string &out){
    for(int i=0;i<kcarpani[x];i++) out += "AR";
    out += "C";
    for(int i=0;i<x/kcarpani[x]-1;i++) out += "RC";
}
void yazdir(int x, string &out){
    if(parent[x]==x){ direktYazdir(x,out); return; }
    yazdir(parent[x],out);
    yazdir(x-parent[x],out);
}
int main(){
    ll x; cin >> x;
    if(x==0){ cout << "A\n"; return 0; }
    for(int i=0;i<700;i++){ saflar[i]=LONG_LONG_MAX; parent[i]=i; kcarpani[i]=-1; }
    for(ll k=1;k<50;k++) for(ll l=0;l<50;l++){
        if(k*(l+1)>=700) continue;
        if(saflar[k*(l+1)] > 2*k+2*l+1){ saflar[k*(l+1)]=2*k+2*l+1; kcarpani[k*(l+1)]=k; }
    }
    for(ll i=1;i<=x;i++) for(ll j=1;j<=i/2;j++){
        if(saflar[i] > saflar[j]+saflar[i-j]){ parent[i]=max(j,i-j); saflar[i]=saflar[j]+saflar[i-j]; }
    }
    string out;
    yazdir(x,out);
    cerr << "saflar[x] (DP-computed optimal length) = " << saflar[x] << "\n";
    cerr << "actual printed length = " << out.size() << "\n";
    cout << out << "\n";
}
