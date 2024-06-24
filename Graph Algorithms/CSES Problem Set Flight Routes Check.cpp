#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
 
#define ll long long
#define fastio ios::sync_with_stdio(false), cin.tie(0);
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define sz(a) (int) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, n) for (int i = 1; i <= n; i++)
#define lowbit(x) x &(-x)
 
const int MAXN = 1e5 + 5;
const int MAXF = 5e18;
// const ll MOD = 1e9 + 7;
vector<ll> G[MAXN];
vector<ll> GT[MAXN];
vector<ll> ans[MAXN];
ll N, M, vis[MAXN], color[MAXN];
ll ansvis[MAXN];
vector<ll> v; // build order
ll scc;

void dfs(ll a){
    vis[a] = 1;
    for(auto it : G[a]){
        if(!vis[it]){
            vis[it] = 1;
            dfs(it);
        }
    }
    v.push_back(a);
}

void dfsscc(ll a){
    color[a] = scc;
    for(auto it : GT[a]){
        if(!color[it]){
            color[it] = scc;
            dfsscc(it);
        }
    }
}

void dfsDirecton(ll a){
    vis[a] = 1;
    for(auto it : G[a]){
        if(!vis[it]){
            vis[it] = 1;
            dfs(it);
        }
    }
}
void solve(){
    cin >> N >> M;
    ll a, b;
    scc = 1;
    for (int i = 1; i <= M; i++){
        cin >> a >> b;
        G[a].push_back(b);
        GT[b].push_back(a);
    }
    for (int i = 1; i <= N; i++){
        if(!vis[i]) dfs(i);
    }
    a = v[sz(v) - 1];
    for(ll i = sz(v) - 1; i >= 0; i--){
        if(!color[v[i]]){
            dfsscc(v[i]);
            scc++;
            if(scc != 2){
                b = v[i];
            }
        }
    }
    if(scc == 2){
        cout << "YES\n";
        return;
    }
    else cout << "NO\n";

    for(ll i = 1; i < N; i++){
        vis[i] = 0;
    }
    dfs(a);
    if(vis[b]) swap(a, b);
    cout << a << " " << b << "\n";
}
 
signed main() {
  fastio int T = 1;
//   cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}