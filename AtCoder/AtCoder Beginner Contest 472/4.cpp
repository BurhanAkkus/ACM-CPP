#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Infinity LONG_LONG_MAX
#define MAX_H 500005
#define MAX_W 500005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


set<int> rowSafe,columnSafe;
void solve(){
    ll h,w,k;
    cin >> h >> w >> k;
    rep(i,0,h,1){
        rowSafe.insert(i);
    }
    rep(i,0,w,1){
        columnSafe.insert(i);
    }
    // true is empty, false is bomb.
    vector<vector<bool>> map(h,vector<bool>(w));    
    vector<vector<ll>> distances(h,vector<ll>(w,LONG_LONG_MAX));    
    rep(i,0,h,1){
        string s;
        cin >> s;
        rep(j,0,w,1){
            map[i][j] = (s[j] == '.');
            if(!map[i][j]){
                rowSafe.erase(i);
                columnSafe.erase(j);
            }
        }
    }

    ll ans = 0;
    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>>pq;
    for(auto safeRow:rowSafe){
        for(auto safeColumn:columnSafe){
            distances[safeRow][safeColumn] = 0;
            pq.push({0,safeRow,safeColumn});
        }
    }
    pair<int,int> directions[]{{1,0},{-1,0},{0,1},{0,-1}};
    while(!pq.empty()){
        auto [distance,x,y] = pq.top();
        pq.pop();
        ans++;
        for(auto [dx,dy] : directions){
            if(x + dx >= 0 && x + dx < h &&
            y + dy >= 0 && y + dy < w &&
            map[x+dx][y+dy] && 
            (distance + 1) <= k && (distance + 1) < distances[x+dx][y+dy]){
                distances[x+dx][y+dy] = distance + 1;
                pq.push({distance+1,x+dx,y+dy});
             }
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
