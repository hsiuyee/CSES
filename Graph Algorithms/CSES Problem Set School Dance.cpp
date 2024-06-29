// refer to: https://yuihuang.com/cses-1696/
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
#include <cstring>
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
 
const int MAXN = 505;
const int MAXF = 5e18;
const ll MOD = 1e9 + 7;

ll N, M, K, a, b, matching[MAXN], ans;
bool vis[MAXN];
vector <ll> G[MAXN];
  
bool dfs(ll x){
    for (ll it : G[x]){
        if (!matching[it]){
            matching[it] = x;
            return true;
        }
        else if (vis[it]) continue;
        else{
            vis[it] = true;
            if (dfs(matching[it])){
                matching[it] = x;
                return true;
            }
        }
    }
    return false;
}
  
void solve() {
    cin >> N >> M >> K;
    for (ll i = 0; i < K; i++){
        cin >> a >> b;
        G[a].push_back(b);
        // only need one direction
    }
    for (int i = 1; i <= N; i++){
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) ans++;
    }
    cout << ans << "\n";
    for (ll i = 1; i <= M; i++){
        if (matching[i]){
            cout << matching[i] << " " << i << "\n";
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