// #include <algorithm>
// #include <bits/stdc++.h>
// #include <deque>
#include <queue>
// #include <cmath>
#include <iostream>
// #include <stdio.h>
// #include <set>
// #include <map>
#include <vector>
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
#define sz(a) (ll) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, n) for (ll i = 1; i <= n; i++)
#define lowbit(x) x &(-x)

const ll MAXN = 1e5 + 5;
// const ll MAXM = 1e2 + 5;
// const ll MAXM = 500 * 501 / 4 + 5;
// const ll INF = 1e18;
// const ll MOD = 1e9 + 7;

ll N, M, color[MAXN];
ll flag;
vector<ll> G[MAXN];

void dfs(ll a, ll pre, ll c) {
  for (auto it : G[a]) {
    if (it == pre)
      continue;
    if (!color[it]) {
      // cout << "a: " << a << " it: " << it << "\n";
      if (c == 1)
        color[it] = 2;
      else
        color[it] = 1;
      dfs(it, a, color[it]);
    } else if (color[it] == color[a]) {
      flag = true;
      return;
    }
  }
}
void solve() {
  cin >> N >> M;
  ll x, y;
  rep(i, M) {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
    // cout << "x: " << x << " y: " << y << "\n";
  }
  rep(i, N) {
    if (!color[i]) {
      color[i] = 1;
      dfs(i, i, 1);
    }
  }
  if (flag)
    cout << "IMPOSSIBLE\n";
  else {
    rep(i, N) cout << color[i] << " ";
  }
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
