    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    #define MAX_N 200002
    #define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))
    #define Infinity LONG_LONG_MAX


    array<ll,105> a;
    void solve(){
        string s;
        cin >> s;
        rep(i,0,s.size(),1){
            if(s[i] != 'A'){
                s[i] = '.';
            }
        }
        cout << s;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll t = 1;
        // cin >> t;
        while(t--){   
            solve();
        }
    }