// refer to: https://yuihuang.com/cses-1696/
#include <algorithm>
#include <stack>
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
 
const int MAXN = 100005;
const int MAXF = 5e18;
const ll MOD = 1e9 + 7;

ll N, M, dfsClock = 0, sccCnt = 0;
ll low[MAXN * 2], dfn[MAXN * 2], color[MAXN*2];
bool ins[MAXN * 2];
vector <ll> g[MAXN * 2];
stack<ll> stk;

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsClock;
    stk.push(u); ins[u] = true;
    for (const auto &v : g[u]) {
        if (!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
        else if (ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++sccCnt;
        do {
            color[u] = sccCnt;
            u = stk.top(); stk.pop(); ins[u] = false;
        } while (low[u] != dfn[u]);
    }
}

void solve() {
    cin >> N >> M;
    for (ll i = 0; i < N; i++) {
        char x, y;
        ll va, a, vb, b;
        cin >> x >> a >> y >> b;
        if (x == '+') va = 1;
        else va = 0;
        if (y == '+') vb = 1;
        else vb = 0;
        // cout << va << " " << a << " " << vb << " " << b << "\n";
        if (va && vb) { // a, b 都真，-a -> b, -b -> a
            g[a + M].push_back(b);
            g[b + M].push_back(a);
        } else if (!va && vb) { // a 假 b 真，a -> b, -b -> -a
            g[a].push_back(b);
            g[b + M].push_back(a + M);
        } else if (va && !vb) { // a 真 b 假，-a -> -b, b -> a
            g[a + M].push_back(b + M);
            g[b].push_back(a);
        } else if (!va && !vb) { // a, b 都假，a -> -b, b -> -a
            g[a].push_back(b + M);
            g[b].push_back(a + M);
        }
    }
    for (int i = 1; i <= (M << 1); ++i) if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= M; ++i) {
        if (color[i] == color[i + M]) { // x 与 -x 在同一强连通分量内，一定无解
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for (int i = 1; i <= M; ++i){
        // cout << color[i] << " " << color[i + M] << "\n";
        if (color[i] < color[i + M]) {
            cout << "+ ";
        }
        else cout << "- ";
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
3 5
+ 1 + 2
- 1 + 3
+ 4 - 2
*/