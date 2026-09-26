#include <bits/stdc++.h>
#include <vector>
#define ll long long
using namespace std;
#define MAX_N 200005
#define MAX_M 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX

constexpr ll nextTwo(ll c){
  ll i = 1;
  while(i < c){
    i<<=1;
  }
  return i;
}

struct SegTree{
  struct Node{
    vector<ll> sorted,prefixSum;
    Node() = default;
    Node(ll value):sorted(1,value),prefixSum(1,value){};
  };
  vector<Node> v;
  SegTree(const vector<ll>& a):v(nextTwo(a.size())*2){
    ll size = nextTwo(a.size());
    rep(i,0,a.size(),1){
      v[size+i] = Node(a[i]);
    }
    build(1,0,size - 1);
  }
  void build(int node,int left,int right){
    if(left == right){return;}
    int mid = left + (right - left) / 2;
    build(node*2,left,mid);
    build(node*2+1,mid+1,right);
    const vector<ll>& leftsVector = v[node*2].sorted;
    const vector<ll>& rightsVector = v[node*2 + 1].sorted;
    auto l = leftsVector.begin();
    auto r = rightsVector.begin();
    while(l != leftsVector.end() && r != rightsVector.end()){
      if(*l < * r){
        v[node].sorted.push_back(*l);
        v[node].prefixSum.push_back((v[node].prefixSum.size() > 0? v[node].prefixSum.back():0) + v[node].sorted.back());
        l++;
      }
      else{
        v[node].sorted.push_back(*r);
        v[node].prefixSum.push_back((v[node].prefixSum.size() > 0? v[node].prefixSum.back():0) + v[node].sorted.back());
        r++;
      }
    }
    while(l != leftsVector.end()){
      v[node].sorted.push_back(*l);
      v[node].prefixSum.push_back((v[node].prefixSum.size() > 0? v[node].prefixSum.back():0) + v[node].sorted.back());
      l++;
    }
    while(r != rightsVector.end()){
      v[node].sorted.push_back(*r);
      v[node].prefixSum.push_back((v[node].prefixSum.size() > 0? v[node].prefixSum.back():0) + v[node].sorted.back());
      r++;
    }
    return;
  }

  ll getClampedSumInRange(int node,int left,int right,int leftRange,int rightRange,ll c, ll d){ 
    // full disaridaysa
    if(left > rightRange || right < leftRange){return 0;}
    // full icerdeyse
    if(left >= leftRange && right <= rightRange){
      const auto& sorted = v[node].sorted;
      const auto& prefixSum = v[node].prefixSum;
      // d'den kucukler d olcak
      int moreThanD = sorted.end() - upper_bound(sorted.begin(),sorted.end(),d);
      // c'den kucukler c olcak.
      int lessThanC = lower_bound(sorted.begin(),sorted.end(),c) - sorted.begin();
      return (moreThanD < prefixSum.size()? prefixSum[prefixSum.size() - moreThanD - 1] : 0) + d * moreThanD
        + c * lessThanC - (lessThanC > 0 ? prefixSum[lessThanC - 1] : 0); 
    }
    // partially icerdeyse
    int mid = left + (right - left) / 2;
    return
    // left Child
     getClampedSumInRange(node*2,left,mid,leftRange,rightRange,c,d) + 
     // right Child
     getClampedSumInRange(node*2 + 1,mid + 1,right,leftRange,rightRange,c,d);
  }
};

void solve(){
  ll n,m,q;
  cin >> n >> m >> q;
  vector<ll> lefts(n),rights(n);
  rep(i,0,n,1){
    cin >> lefts[i] >> rights[i];
  }
  SegTree leftSegTree{lefts},rightSegTree{rights};
  rep(i,0,q,1){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    a--;b--;
    cout << rightSegTree.getClampedSumInRange(1,0,nextTwo(n) - 1,a,b,c - 1,d)
    - leftSegTree.getClampedSumInRange(1,0,nextTwo(n) - 1,a,b,c,d + 1) + b - a + 1 << '\n';
  }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}