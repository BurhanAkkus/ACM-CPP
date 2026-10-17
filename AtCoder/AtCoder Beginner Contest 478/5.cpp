#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<set<int>,MAX_N> t1s,t0s;
array<int,MAX_N> t1InDegree,t0InDegree,layer;
struct dsu
{
    vector<int> parent;
    vector<int> size;
    int n;
    public:
    dsu(int n) :parent(n), size(n, 1),n(n){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        while(x != parent[x]){
        x = parent[x] = parent[parent[x]];}
        return x;
    }
    int union_(int a,int b){
        if( a >= (int)parent.size() || b >=(int) parent.size() || a < 0 || b < 0){
            return -1;
        }
        a = find(a);
        b = find(b);
        
        if( a == b) return -1;
        if(size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
        for(auto t1:t1s[b]){
            t1s[a].insert(t1);
        }
        for(auto t0:t0s[b]){
            t0s[a].insert(t0);
        }
        return b;
    }
    int size_(int a){
        a = find(a);
        return size[a];
    }
};

int temsilci(dsu& dsu,int i){
    return dsu.find(i);
}

bool dfs(dsu& dsu, int currentNode, vector<int> path, map<int,int> pathIndices, int latestT1Edge){
    int temsil = temsilci(dsu,currentNode);
    // There is a cycle!
    if(pathIndices.contains(temsil)){
        int cycleStart = pathIndices[temsil];
        // Cycle contains t1Edge
        if(latestT1Edge >= cycleStart){
            return false;
        }
        // Union all cycle members.
        for(int i = path.size() - 1; i >= cycleStart; i--){
            int cycleMember = path[i];
            dsu.union_(cycleStart,cycleMember);
            path.pop_back();
            pathIndices.erase(cycleMember);
        }
        return true;
    }
    path.push_back(temsil);
    pathIndices.emplace(temsil,path.size() - 1);

    // No cycle in path anymore. Path.back() = temsil.
    for(int neighbour:t1s[temsil]){
        neighbour = temsilci(dsu,neighbour);
        if(!dfs(dsu,temsilci(dsu,neighbour),path,pathIndices,path.size() - 1)){
            return false;
        }
    }
    for(int neighbour:t0s[temsil]){
        neighbour = temsilci(dsu,neighbour);
        if(!dfs(dsu,temsilci(dsu,neighbour),path,pathIndices,latestT1Edge)){
            return false;
        }
    }
    return true;    
}

void solve(){   
    ll n,q;
    cin >> n >> q;
    dsu d{n};
    layer.fill(-1);
    rep(i,0,q,1){
        ll type,s,d;
        cin >> type >> s >> d;
        s--;d--;
        if(type == 1){
            t1s[d].insert(s);
            t1InDegree[s]++;
        }
        else{
            t0s[d].insert(s);
            t0InDegree[s]++;
        }
    }
    queue<int> queue;
    rep(i,0,n,1){
        if(t1InDegree[i] == 0){
            queue.push(i);
            layer[i] = 0;
        }
    }
    if(queue.empty()){
        cout << "No";
        return;
    }
    // DFS with cycle detection.
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