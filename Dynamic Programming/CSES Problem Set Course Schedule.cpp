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

ll N, M, vis[MAXN];
ll indeg[MAXN];
vector<ll> G[MAXN];

void solve() {
  cin >> N >> M;
  ll x, y;
  rep(i, M) {
    cin >> x >> y;
    G[x].push_back(y);
    indeg[y]++;
  }
  vector<ll> ans;
  queue<ll> temp;
  rep(i, N) {
    if (indeg[i] == 0)
      temp.push(i);
  }
  ll f = 0;
  while (temp.size()) {
    f = 0;
    ll now = temp.front();
    temp.pop();
    ans.push_back(now);
    for (auto it : G[now]) {
      indeg[it]--;
      if (indeg[it] == 0) {
        temp.push(it);
        f = 1;
      }
    }
  }
  if (sz(ans) != N) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (auto it : ans)
    cout << it << " ";
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
