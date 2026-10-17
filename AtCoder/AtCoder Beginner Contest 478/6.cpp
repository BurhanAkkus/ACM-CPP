#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))


// Lazy Propagation Segment Tree: range add, range min query.
struct LazySegmentTree {
    int n;
    vector<ll> tree, lazy;

    LazySegmentTree(int size) : n(size), tree(4*size, 0), lazy(4*size, 0) {}
    LazySegmentTree(const vector<ll>& a) : n(a.size()), tree(4*(int)a.size(), 0), lazy(4*(int)a.size(), 0) {
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vector<ll>& a){
        if(l == r){ tree[node] = a[l]; return; }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid, a);
        build(node << 1 | 1, mid + 1, r, a);
        tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
    }

    void applyAdd(int node, ll x){
        tree[node] += x;
        lazy[node] += x;
    }
    void push(int node){
        if(lazy[node]){
            applyAdd(node << 1, lazy[node]);
            applyAdd(node << 1 | 1, lazy[node]);
            lazy[node] = 0;
        }
    }
    // add x to every index in [queryLeft, queryRight] (inclusive)
    void addRange(int currentNode, int currentNodeLeft, int currentNodeRight, int queryLeft, int queryRight, ll x){
        if(currentNodeLeft > queryRight || currentNodeRight < queryLeft) return;
        if(queryLeft <= currentNodeLeft && currentNodeRight <= queryRight){
            applyAdd(currentNode, x);
            return;
        }
        push(currentNode);
        int mid = (currentNodeLeft + currentNodeRight) >> 1;
        addRange(currentNode << 1, currentNodeLeft, mid, queryLeft, queryRight, x);
        addRange(currentNode << 1 | 1, mid + 1, currentNodeRight, queryLeft, queryRight, x);
        tree[currentNode] = min(tree[currentNode << 1], tree[currentNode << 1 | 1]);
    }
    ll queryMin(int currentNode, int currentNodeLeft, int currentNodeRight, int queryLeft, int queryRight){
        if(currentNodeLeft > queryRight || currentNodeRight < queryLeft) return Infinity;
        if(queryLeft <= currentNodeLeft && currentNodeRight <= queryRight){
            return tree[currentNode];
        }
        push(currentNode);
        int mid = (currentNodeLeft + currentNodeRight) >> 1;
        return min(queryMin(currentNode << 1, currentNodeLeft, mid, queryLeft, queryRight),
                    queryMin(currentNode << 1 | 1, mid + 1, currentNodeRight, queryLeft, queryRight));
    }

    // add x to every index i with i >= l and i < r
    void update(int l, int r, ll x){
        if(l >= r) return;
        addRange(1, 0, n - 1, l, r - 1, x);
    }
    // min over every index i with i >= l and i < r
    ll queryMin(int l, int r){
        return queryMin(1, 0, n - 1, l, r);
    }
};

array<int,MAX_N> a;
void solve(){   
    ll n,q;
    cin >> n;
    string s;
    cin >> s;
    cin >> q;
    LazySegmentTree st{n};
    rep(i,0,n,1){
        st.update(i,n,(-1 + (2 * (s[i] == 'A'))));
    }
    rep(i,0,q,1){
        ll type,l;
        char c;
        cin >> type >> l;
        l--;
        if(type == 1){
            cin >> c;
            if(c == s[l]){continue;}
            else if(c == 'B'){
                st.update(l,n,-2);
            }else{
                st.update(l,n,2);
            }
            s[l] = c;
        }
        else if(type == 2){
            ll r;
            cin >> r;
            r--;
            if(st.queryMin(l,r) - (l > 0? st.queryMin(l-1,l-1) : 0)  >= 0){
                cout <<"Yes\n";
            }
            else{
                cout <<"No\n";
            }
        }
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