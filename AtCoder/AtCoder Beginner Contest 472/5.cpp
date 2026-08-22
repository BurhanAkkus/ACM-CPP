#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 2000005
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<vector<int>,MAX_N> edges;

vector<int> oddCycle;
array<int,MAX_N> depthArr, parentArr;

bool dfs(int curr, int par){
    for(auto dest:edges[curr]){
        if(dest == par) continue;
        if(depthArr[dest] != -1){
            if((depthArr[curr] - depthArr[dest]) % 2 == 0){
                int v = curr;
                while(v != dest){
                    oddCycle.push_back(v);
                    v = parentArr[v];
                }
                oddCycle.push_back(dest);
                return true;
            }
        }
        else{
            depthArr[dest] = depthArr[curr] + 1;
            parentArr[dest] = curr;
            if(dfs(dest,curr)){return true;}
        }
    }
    return false;
}

void solve(){
    oddCycle.clear();
    ll n,m;
    cin >> n >> m;
    rep(i,1,n + 1,1){
        edges[i].clear();
        depthArr[i] = -1;
    }
    rep(i,0,m,1){
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    depthArr[1] = 0;
    parentArr[1] = -1;
    if(dfs(1,-1)){
        cout << oddCycle.size() << "\n";
        for(auto oddCycleMember: oddCycle){
            cout << oddCycleMember << " ";
        }
        cout<<"\n";
        return;
    }
    cout << "-1\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
