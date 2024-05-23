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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define lowbit(x) x &(-x)

const ll MAXN = 2e5 + 5;
// const ll MAXM = 1e2 + 5;
// const ll MAXM = 500 * 501 / 4 + 5;
// const ll INF = 1e18;
// const ll MOD = 1e9 + 7;

ll N, M, vis[MAXN], tran[MAXN];
ll point[MAXN];
vector<ll> G[MAXN];
vector<ll> ans;
ll flag;

void solve() {
  cin >> N >> M;
  ll x, y;
  rep(i, M) {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
    // cout<<"x: "<<x<<" y: "<<y<<"\n";
  }
  queue<ll> q;
  q.push(1);
  vis[1]=1;
  while (q.size()) {
    ll now = q.front();
    q.pop();
    if (now == N) {
      flag = true;
      while (now != 1) {
        ans.push_back(now);
        now = tran[now];
      }
      ans.push_back(1);
      break;
    }
    for (auto it : G[now]) {
      if (!vis[it]) {
        vis[it] = 1;
        tran[it] = now;
        q.push(it);
      }
    }
  }
  if (flag) {
    cout << sz(ans) << "\n";
    for (ll i = sz(ans) - 1; i >= 0; i--)
      cout << ans[i] << " ";
  } else
    cout << "IMPOSSIBLE\n";
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
