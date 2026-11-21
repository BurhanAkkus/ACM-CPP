#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

const long long MAX_N = 5000;

std::array<ll,MAX_N+2> a;
void solve(){
    ll n;
    cin >> n;
    rep(i,0,n,1){
        cin >> a[i];
    }
    if(n == 1){
        std::cout << "1\n";
        return;
    }
    ll ans{2};
    rep(l,0,n,1){
        ll sameCounter{1},beforeLessCounter{0},lessCounter{0};
        // the ones before me.
        for(int j = l - 1; j >=0 ; --j){
            if(a[j] > a[l]){break;}
            else{beforeLessCounter++;}
        }
        // the ones after me
        rep(r,l+1,n,1){
            if(a[r] > a[l]){
                break;
            }
            if(a[r] == a[l]){
                sameCounter++;
                // check if can Span?
                if(sameCounter + std::min(sameCounter,lessCounter + beforeLessCounter) >= r - l + 1){
                    ans = std::max(ans,sameCounter + std::min(sameCounter,lessCounter + beforeLessCounter));
                }
            }
            else{
                lessCounter++;
                if(sameCounter + std::min(sameCounter,lessCounter + beforeLessCounter) >= r - l + 1){
                    ans = std::max(ans,sameCounter + std::min(sameCounter,lessCounter + beforeLessCounter));
                }
            }
        }
    }
    std::cout << ans << "\n";  
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
}
