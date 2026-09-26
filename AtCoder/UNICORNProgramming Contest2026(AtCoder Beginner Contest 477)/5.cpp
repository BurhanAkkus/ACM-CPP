#include <bits/stdc++.h>
#include <atcoder/segtree>
#define ll long long
using namespace std;
using namespace atcoder;
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

array<ll,MAX_N> a,b,prefixSums,distances;


ll n,q;

void bfs(){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> toProcess;
    rep(i,0,n,1){
        toProcess.push(pair{b[i],i});
    }
    while(!toProcess.empty()){
        auto [dist,i] = toProcess.top();
        toProcess.pop();
        if(distances[i] <= dist){continue;}
        distances[i] = dist;
        // move clockwise
        toProcess.push(pair{dist + a[i],(i + 1) % n});
        //move counter clockwise
        toProcess.push(pair{dist + a[(i - 1 + n) % n],(i - 1 + n) % n});
    }
}

void solve(){
    cin >> n >> q;
    distances.fill(LONG_LONG_MAX);
    rep(i,0,n,1){
        cin >> a[i];
    }
    rep(i,0,n,1){
        cin >> b[i];
    }
    prefixSums[0] = a[0];
    rep(i,1,n,1){
        prefixSums[i] = prefixSums[i-1] + a[i];
    }
    bfs();

    rep(i,0,q,1){
        ll s,t;
        cin >> s >> t;
        s--;t--;
        ll m{min(s,t)};
        t = max(s,t);
        s = m;
        if(s == t){cout << "0\n";continue;}
        if(t == n){cout << distances[s] << endl;continue;}
        // clockwise s->t
        // ll candidate1 = segTree.prod(s,t) + distances[t] - (s>0?prefixSums[s-1]:0);
        // // clockwise t->s
        // ll candidate2 = min(segTree.prod(t,n) - prefixSums[t-1],segTree.prod(0,s +) + prefixSums[n-1] - prefixSums[t-1]) +  distances[s];
        // // cycle
        // ll candidate3 = min(prefixSums[t] - (s > 0 ? prefixSums[s - 1] : 0), prefixSums[n-1] - prefixSums[t - 1] + (s>0?prefixSums[s-1]:0));
        // cout << min(min(candidate1,candidate2),candidate3) << endl;
        ll candidate1 = distances[s] + distances[t];
        ll candidate2 = prefixSums[t - 1] - (s > 0? prefixSums[s-1] : 0);
        ll candidate3 = prefixSums[n-1] - prefixSums[t-1] + (s>0?prefixSums[s-1]:0);
        cout << min(min(candidate1,candidate2),candidate3) << endl;
    }
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
