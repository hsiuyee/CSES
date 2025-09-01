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
const int MAXM = 2e5 + 5;
const int MAXF = 5e18;
// const ll MOD = 1e9 + 7;

ll N, M, indeg[MAXN], outdeg[MAXN], vis[MAXM];
vector<pll> G[MAXN];
vector<ll> ans;

void dfs(ll node) {
	while (!G[node].empty()) {
		auto [son, idx] = G[node].back();
		G[node].pop_back();
		if (vis[idx]) { continue; }
		vis[idx] = true;
		dfs(son);
	}
	ans.push_back(node);
}

void solve(){
    cin >> N >> M;
    ll a, b;
    for (int i = 0; i < M; i++){
        cin >> a >> b;
        G[a].push_back(mkp(b, i));
        indeg[b]++;
        outdeg[a]++;
    }
    for(ll i = 2; i <= N-1; i++){
        if(indeg[i] != outdeg[i]){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    if ((outdeg[1] - indeg[1] != 1) or (indeg[N] - outdeg[N] != 1)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    // G[b].push_back(mkp(a, M));
    dfs(1);
    if (ans.size() != M + 1) cout << "IMPOSSIBLE\n";
    else{
        reverse(all(ans));
        for (ll i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
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

/*
Input:
5 6
1 2
1 3
2 4
2 5
3 1
4 2

Output:
1 3 1 2 4 2 5
*/