#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

using Edge = tuple<int,int>;//  dest, color

array<list<Edge>,MAX_N> edges;
array<int,MAX_N> firstColor;
array<int,MAX_N> visitCount;
void solve(){   
    ll n,m;
    cin >> n >> m;
    rep(i,0,m,1){
        int source,dest,color;
        cin >> source >> dest >> color;
        edges[source].emplace_back(dest,color);
    }

    // BFS
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,std::greater<tuple<int,int,int>>> q; // dist,lastEdgeColor,current
    visitCount[1] = 1;
    q.emplace(0,-1,1);
    while(!q.empty()){
        auto [dist,lastEdgeColor,current] = q.top();
        q.pop();
        if(current == n){
            cout << dist;
            return;
        }
        for(auto&[dest,color]:edges[current]){
            if(color == lastEdgeColor){continue;}
            if(visitCount[dest] == 0){
                visitCount[dest] = 1;
                firstColor[dest] = color;
                q.emplace(dist + 1, color, dest);
            }
            else if(visitCount[dest] == 1 && firstColor[dest] != color){
                visitCount[dest] = 2;
                q.emplace(dist + 1, color, dest);
            }
        }
    }
    cout << -1;
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