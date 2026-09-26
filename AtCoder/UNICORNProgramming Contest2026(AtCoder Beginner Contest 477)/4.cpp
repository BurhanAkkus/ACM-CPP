#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 500005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX


array<char,MAX_N> colors;
void solve(){
    ll n,q;
    cin >> n >> q;
    set<ll> kalanTruelar,kalanFalselar;
    vector<pair<ll,ll>> query1ler;
    vector<pair<ll,char>> query2ler;
    colors.fill('a');
    rep(i,0,n,1){
        kalanTruelar.insert(i);
    }
    rep(i,0,q,1){
        ll type;
        cin >> type;
        if(type == 1){
            ll x;
            cin >> x;
            x--;
            query1ler.push_back(pair{i,x});
        }
        if(type == 2){
            char c;
            cin >> c;
            query2ler.push_back(pair{i,c});
        }
    }
    ll lastQuery2 = (query2ler.size() > 0 ? query2ler.back().first : -1);
    while(!query1ler.empty() && query1ler.back().first > lastQuery2) query1ler.pop_back();

    for(auto [i,x]:query1ler){
        if(kalanTruelar.contains(x)){
            kalanTruelar.erase(x);
            kalanFalselar.insert(x);
        }
        else if(kalanFalselar.contains(x)){
            kalanFalselar.erase(x);
            kalanTruelar.insert(x);
        }
    }
    for(auto it = query2ler.rbegin(); it != query2ler.rend(); it++){
        auto [i,c] = *it;
        while(query1ler.size() > 0 && query1ler.back().first > i){
            auto x = query1ler.back().second;
            if(kalanTruelar.contains(x)){
                kalanTruelar.erase(x);
                kalanFalselar.insert(x);
            }
            else if(kalanFalselar.contains(x)){
                kalanFalselar.erase(x);
                kalanTruelar.insert(x);
            }
            query1ler.pop_back();
        }
        for(auto x:kalanTruelar){
            colors[x] = c;
        }
        kalanTruelar.clear();
    }
    rep(i,0,n,1){
        cout << colors[i];
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}