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
#define rep(i, n) for (ll i = 1; i <= N; i++)
#define lowbit(x) x &(-x)

const ll MAXN = 1e3 + 5;
// const ll MAXM = 1e2 + 5;
// const ll MAXM = 500 * 501 / 4 + 5;
// const ll INF = 1e18;
// const ll MOD = 1e9 + 7;

ll N, M, vis[MAXN][MAXN];
char G[MAXN][MAXN];
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
ll sign[4] = {'D', 'U', 'R', 'L'};
char GG[MAXN][MAXN];
ll flag;
pll s, e;
vector<char> ans;

bool isVaild(ll x, ll y) {
  return 1 <= x and x <= N and 1 <= y and y <= M and !vis[x][y] and
         G[x][y] != '#';
}

void dfs(pll a) {
  if(a==s) return;
  for (ll i = 0; i < 4; i++) {
    if (sign[i] == GG[a.F][a.S]) {
      ans.push_back(sign[i]);
      // cout<<a.F<<" "<<a.S<<"\n";
      dfs(mkp(a.F - dx[i], a.S - dy[i]));
      continue;
    }
  }
}

void solve() {
  cin >> N >> M;
  rep(i, N) for (ll j = 1; j <= M; j++) {
    cin >> G[i][j];
    if (G[i][j] == 'A') {
      s = mkp(i, j);
    }
    if (G[i][j] == 'B') {
      e = mkp(i, j);
    }
  }
  queue<pll> q;
  q.push(s);
  while (q.size()) {
    ll nowx = q.front().F;
    ll nowy = q.front().S;
    q.pop();
    // cout << nowx << " " << nowy << "\n";
    if (mkp(nowx, nowy) == e) {
      flag = 1;
      dfs(e);
      break;
    }
    for (ll i = 0; i < 4; i++) {
      if (isVaild(nowx + dx[i], nowy + dy[i])) {
        GG[nowx + dx[i]][nowy + dy[i]] = sign[i];
        vis[nowx + dx[i]][nowy + dy[i]] = 1;
        q.push(mkp(nowx + dx[i], nowy + dy[i]));
      }
    }
  }
  if (flag) {
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (ll i = sz(ans) - 1; i >= 0; i--)
      cout << ans[i];
  } else
    cout << "NO\n";
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
