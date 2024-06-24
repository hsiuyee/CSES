// refer to: https://yuihuang.com/cses-1691/
// find Euler Tour
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

ll N, M;
set<ll> G[MAXN];
vector<ll> ans;

void dfs(int x){
    while (G[x].size()){
        int now = *G[x].begin();
        G[now].erase(x);
        G[x].erase(now);
        dfs(now);
    }
    ans.push_back(x);
}

void solve(){
    cin >> N >> M;
    ll a, b;
    for (int i = 1; i <= M; i++){
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }
    for(ll i = 1; i <= N; i++){
        if(G[i].size() % 2 != 0){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    dfs(1);
    if (ans.size() != M + 1) cout << "IMPOSSIBLE\n";
    else{
        for (auto it : ans){
            cout << it << " ";
        }
    }
}
 
signed main() {
  fastio int T = 1;
//   cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}