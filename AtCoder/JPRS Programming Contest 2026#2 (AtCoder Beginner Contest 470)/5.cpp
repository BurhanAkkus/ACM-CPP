#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX_N 205
#define MAX_L 205
#define rep(i,start,end,increment) for(ll i=(start);i<(end);i+=(increment))

// cift sayisi, known, life;
static double dp[MAX_N][MAX_N][MAX_L];
static bool  vis[MAX_N][MAX_N][MAX_L];

// Beklenen toplanan CIFT sayisi (puan degil).
double dpHesapla(int ciftSayisi,int known,int life){
    if(ciftSayisi <= 0 || life <= 0){
        return 0;
    }
    if(vis[ciftSayisi][known][life]){
        return dp[ciftSayisi][known][life];
    }
    vis[ciftSayisi][known][life] = true;

    // masadaki kapali ve degeri bilinmeyen kart sayisi
    int bilinmeyen = 2*ciftSayisi - known;

    if(known >= ciftSayisi){
        // her degerden bir kart biliniyor -> her acis bedava eslesme
        return dp[ciftSayisi][known][life] = 1 + dpHesapla(ciftSayisi-1, known-1, life);
    }
    // knownlarin arasinda hic cift yok! known = 1 kartini bildigim match sayisi.

    double res = 0;

    // ilk actigim kart bildigim bir kartin esi cikti!
    double bildigimeDenkGelmeIhtimali = (1.0 * known) / bilinmeyen;
    if(known > 0){
        res += bildigimeDenkGelmeIhtimali * (dpHesapla(ciftSayisi-1, known-1, life) + 1);
    }
    // ilk actigimi bilmiyorum, ikinci actigim ilk actigimla ayni denk geldi!
    double rastgeleDenkGelmeIhtimali = 1.0 / (bilinmeyen - 1);
    res += (1.0 - bildigimeDenkGelmeIhtimali) * rastgeleDenkGelmeIhtimali * (dpHesapla(ciftSayisi-1, known, life) + 1);
    // ilk actigimi bilmiyorum, ikinci actigim ilk actigimla ayni degil
    if(life > 1 && bilinmeyen > 2){
        double kalan = 1.0 * (1.0 - bildigimeDenkGelmeIhtimali) * (1.0 - rastgeleDenkGelmeIhtimali);
        // ikinci actigim bildiklerimden birinin esi -> can gitti ama bedava cift kazandim
        double bildiklerimdenOlmaIhtimali = 1.0 * known / (bilinmeyen - 2);
        if(known > 0){
            res += kalan * bildiklerimdenOlmaIhtimali * (dpHesapla(ciftSayisi-1, known, life-1) + 1);
        }
        // ikinci actigim tamamen yeni bir kart
        res += kalan * (1.0 - bildiklerimdenOlmaIhtimali) * dpHesapla(ciftSayisi, known+2, life-1);
    }
    return dp[ciftSayisi][known][life] = res;
}

void solve(){
    ll n,l;
    cin >> n >> l;
    ll sum = 0;
    rep(i,0,n,1){
        ll c;
        cin >> c;
        sum+=c;
    }
    // Strateji degerlerden bagimsiz -> her cift esit olasilikla toplanir.
    double beklenenCift = dpHesapla((int)n, 0, (int)l);
    cout << fixed << setprecision(10) << (double)sum * beklenenCift / (double)n << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
