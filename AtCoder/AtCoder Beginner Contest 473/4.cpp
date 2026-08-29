#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define Infinity LONG_LONG_MAX
#define MAX_N 200005
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

vector<vector<int>> sequences;
ll n,k;

bool sequenceComparator(vector<int>& a, vector<int>&b){
    for(auto i = n-1; i >= 0; i--){
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }
    return false;
}

void sequenceGenerator(int k, int max, vector<int>& seq){
    if(max == 1){
        seq.push_back(k);
        vector<int> c = seq;
        sequences.push_back(c);
        seq.pop_back();
        return;
    }
    rep(i,0,k/max + 1,1){
        seq.push_back(i);
        sequenceGenerator(k-i*max,max-1,seq);
        seq.pop_back();
    }
}

void solve(){   
    cin >> n >> k;
    vector<int> seq;
    sequenceGenerator(k,n,seq);
    sort(sequences.begin(),sequences.end(),sequenceComparator);
    for(auto& seq:sequences){
        for(auto it = seq.rbegin(); it != seq.rend(); it++){
            cout << *it << " ";
        }
        cout << "\n";
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