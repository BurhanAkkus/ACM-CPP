#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 30005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

vector<int> pluses,minuses;
void solve(){   
    pluses.clear();
    minuses.clear();
    ll x,y,m;
    cin >> x >> y >> m;
    string s;
    cin >> s;
    ll ans{x+y};
    rep(i,0,m,1){
        if(s.at(i) == '+'){
            pluses.push_back(i);
        }
        else{
            minuses.push_back(i);
        }
    }
    rep(i,0,m,1){
        if(x == 0 && y == 0) break;
        ans = max(ans,x+y);
            if(s.at(i) == '+'){
                if(y > 0){
                    y++;
                }
                else{
                    x--;
                    y++;
                }
            }
            else{
                if(y > 1){
                    x++;
                    y--;
                } else if(y == 0){
                    x--;
                }
                else{
                    // y = 1;
                    // if next + is more than x away, lower y.
                    // if there are no more pluses, lower y.
                    auto upperBound = upper_bound(pluses.begin(),pluses.end(),i);
                    if(upperBound == pluses.end() || (*upperBound - i > x)){
                        x++;
                        y--;
                    }
                    else{
                        x--;
                    }
                }
            }
    }

    ans = max(ans,x+y);
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
}