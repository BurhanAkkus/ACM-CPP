#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 200005
#define MAX_M 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
#define Infinity LONG_LONG_MAX

constexpr int carmichael_constexpr(int n){
  if(n==998244353)return 998244352;
  if(n==1000000007)return 1000000006;
  if(n<=1)return n;
  int res=1;
  int t=0;
  while(n%2==0){
    n/=2;
    t++;
  }
  if(t==2)res=2;
  else if(t>=3)res=1<<(t-2);
  for(int i=3;i*i<=n;i++)if(n%i==0){
    int c=0;
    while(n%i==0){
      n/=i;
      c++;
    }
    int prod=i-1;
    for(int j=0;j<c-1;j++)prod*=i;
    res=std::lcm(res,prod);
  }
  if(n!=1)res=std::lcm(res,n-1);
  return res;
}
template<int m>
struct mod_int{
private:
  static constexpr unsigned int umod=static_cast<unsigned int>(m);
  static constexpr unsigned int car=carmichael_constexpr(m);
  using uint=unsigned int;
  using mint=mod_int;
  uint v;
  static_assert(m<uint(1)<<31);
  mint sqrt_impl()const{
    if(this->val()<=1)return *this;
    // evaluated at compile time, depending on m
    // ToDo
    // understand and implement
    if constexpr(m%8==1){
      mint b=2;
      while(b.pow((m-1)/2).val()==1)b++;
      int m2=m-1,e=0;
      while(m2%2==0)m2>>=1,e++;
      mint x=this->pow((m2-1)/2);
      mint y=(*this)*x*x;
      x*=*this;
      mint z=b.pow(m2);
      while(y.val()!=1){
        int j=0;
        mint t=y;
        while(t.val()!=1)t*=t,j++;
        z=z.pow(1<<(e-j-1));
        x*=z;
        z*=z;
        y*=z;e=j;
      }
      return x;
    }
    else if constexpr(m%8==5){
      mint ret=this->pow((m+3)/8);
      if((ret*ret).val()==this->val())return ret;
      else return ret*mint::raw(2).pow((m-1)/4);
    }
    else{
      return this->pow((m+1)/4);
    }
  }
public:
  using value_type=uint;
  mod_int():v(0){}
  template<typename T,std::enable_if_t<std::is_signed_v<T>,std::nullptr_t> =nullptr>
  mod_int(T a){
    a%=m;
    if(a<0)v=a+umod;
    else v=a;
  }
  template<typename T,std::enable_if_t<std::is_unsigned_v<T>,std::nullptr_t> =nullptr>
  mod_int(T a):v(a%umod){}
  static constexpr mint raw(int a){
    mint ret;
    ret.v=a;
    return ret;
  }
  inline uint val()const{return this->v;}
  static constexpr int mod(){return m;}
  inline mint &operator+=(const mint &b){
    this->v+=b.v;
    if(this->v>=umod)this->v-=umod;
    return *this;
  }
  inline mint &operator-=(const mint &b){
    this->v-=b.v;
    if(this->v>=umod)this->v+=umod;
    return *this;
  }
  inline mint &operator*=(const mint &b){
    this->v=((unsigned long long)this->v*b.v)%umod;
    return *this;
  }
  inline mint &operator/=(const mint &b){
    *this*=b.inv();
    return *this;
  }
  inline mint operator+()const{return *this;}
  inline mint operator-()const{return mint()-*this;}
  friend inline mint operator+(const mint &a,const mint &b){return mint(a)+=b;}
  friend inline mint operator-(const mint &a,const mint &b){return mint(a)-=b;}
  friend inline mint operator*(const mint &a,const mint &b){return mint(a)*=b;}
  friend inline mint operator/(const mint &a,const mint &b){return mint(a)/=b;}
  friend inline bool operator==(const mint &a,const mint &b){return a.val()==b.val();}
  friend inline bool operator!=(const mint &a,const mint &b){return !(a==b);}
  friend inline bool operator<(const mint &a,const mint &b){return a.val()<b.val();}
  friend inline bool operator>(const mint &a,const mint &b){return a.val()>b.val();}
  friend inline bool operator<=(const mint &a,const mint &b){return a.val()<=b.val();}
  friend inline bool operator>=(const mint &a,const mint &b){return a.val()>=b.val();}
  inline mint operator++(int){
    mint ret=*this;
    *this+=mint::raw(1);
    return ret;
  }
  inline mint operator--(int){
    mint ret=*this;
    *this-=mint::raw(1);
    return ret;
  }
  mint pow(long long n)const{
    mint ret=mint::raw(1),a(*this);
    while(n){
      if(n&1)ret*=a;
      a*=a;
      n>>=1;
    }
    return ret;
  }
  inline mint inv()const{
    assert(this->v!=0);
    return pow(car-1);
  }
  std::optional<mint>sqrt()const{
    if(this->val()<=1||this->pow((m-1)/2)==1)return std::make_optional(this->sqrt_impl());
    else return std::nullopt;
  }
  static constexpr unsigned int order(){return car;}
  friend std::istream &operator>>(std::istream &is,mint &b){
    long long a;
    is>>a;
    b=mint(a);
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os,const mint &b){
    os<<b.val();
    return os;
  }
};

using mint =mod_int<998244353>;

mint fact[MAX_N];
mint inv_fact[MAX_N];
void precompute_factorials() {
    fact[0] = 1;
    for (ll i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i - 1] * mint(i));
    }
    inv_fact[MAX_N-1] = fact[MAX_N-1].inv();  // one modular inverse
    for (ll i = MAX_N-2; i >= 0; i--)
        inv_fact[i] = inv_fact[i+1] * mint(i+1);  // work backwards
}

#define block_size 256

mint combination(int n,int k){
    if(k<0||k>n)return mint(0);
    return fact[n]*inv_fact[k]*inv_fact[n-k];
}

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
        return b;
    }
    int size_(int a){
        a = find(a);
        return size[a];
    }
};
array<vector<int>,MAX_N> uyeler;
void solve(){
  ll n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  dsu d(n + 1);
  rep(i,0,m,1){
    ll a,b;
    cin >> a >> b;
    d.union_(a,b);
  }
  rep(i,1,n+1,1){
    d.find(i);
  }

  mint ans = 1;
  rep(i,1,n+1,1){
    uyeler[d.find(i)].push_back(i);
  }
  array<int,26> kacKereTekrarliyor;
  
  bool canPumpInfinitely = false;
  for(auto& cycle:uyeler){
    rep(i,0,26,1){
      kacKereTekrarliyor[i] = 0;
    }
    for(auto uye:cycle){
      kacKereTekrarliyor[s[uye - 1] - 'a']++;
    }
    mint benimKatkim{fact[cycle.size()]};
    for(auto& count : kacKereTekrarliyor) {
      if(count > 1){
        canPumpInfinitely = true;
      }
      benimKatkim /= fact[count];
    }
    ans *= benimKatkim;
  }
  
  if(!canPumpInfinitely) ans /= 2;
  cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute_factorials();
    solve();
}