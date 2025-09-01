// #include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <tuple>
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
#define lowbit(x) x&(-x)

const ll MAXN = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

ll N, M, dis[MAXN][MAXN];
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
char c[4] = {'D', 'U', 'R', 'L'};
pll start, from[MAXN][MAXN];;
queue<pll> qu;
vector<char> ans;
bool bfs_start = false, possible = false;

pll operator+(const pll& a, const pll& b) {
  return pll(a.first + b.first, a.second + b.second);
}

void check(pll now, pll nxt) {
  ll distance = dis[now.F][now.S];
  if (distance + 1 < dis[nxt.F][nxt.S]) {
    dis[nxt.F][nxt.S] = distance + 1;
    qu.push(nxt);
    from[nxt.F][nxt.S] = now;
  }
}

void retrace(pll now) {
  pll pre = from[now.F][now.S];
  if (pre == pll(0, 0)) return;
  for (ll i = 0; i < 4; i++) {
    if (pre + pll(dx[i], dy[i]) == now) {
      ans.push_back(c[i]);
      break;
    }
  }
  retrace(pre);
}

void bfs() {
  while (qu.size()) {
    pll now = qu.front(), nxt;
    qu.pop();
    for (ll i = 0; i < 4; i++) {
      nxt = now + pll(dx[i], dy[i]);
      check(now, nxt);
    }
    if (bfs_start and (now.F == 1 or now.S == 1 or now.F == N or now.S == M)) {
      cout << "YES\n";
      cout << dis[now.F][now.S] << "\n";
      possible = true;
      retrace(now);
      return;
    }
  }
}

void solve() {
  cin >> N >> M;
  string s;
  for (ll i = 1; i <= N; i++) {
    cin >> s;
    s = ' ' + s;
    for (ll j = 1; j <= M; j++) {
      dis[i][j] = INF;
      if (s[j] == '#') dis[i][j] = 0;
      else if (s[j] == 'M') {
        qu.push(pll(i, j));
        dis[i][j] = 0;
      }
      else if (s[j] == 'A') {
        start.F = i;
        start.S = j;
      }
    }
  }
  bfs();
  bfs_start = true;
  from[start.F][start.S] = pll(0, 0);
  dis[start.F][start.S] = 0;
  qu.push(start);
  bfs();
  if (possible) {
    reverse(all(ans));
    for (auto it : ans) cout << it;
    cout << "\n";
  }
  else cout << "NO\n";
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}

/*
Input:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Output:
YES
5
RRDDR
*/