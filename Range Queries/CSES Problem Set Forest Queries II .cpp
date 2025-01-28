// refer to: https://hackmd.io/@thanksone/CSESPLANII
// #include<bits/stdc++.h>
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
const ll INF = 1e9;
const ll MOD = 1234567891;
const ll P = 989898989;

struct BIT_2D {
  vector<vector<ll> > vec;
  BIT_2D() : vec(MAXN, vector<ll>(MAXN, 0)) {}

  void update(ll x, ll y, ll v) {
    for (ll i = x; i < MAXN; i += lowbit(i)) {
      for (ll j = y; j < MAXN; j += lowbit(j)) {
        vec[i][j] += v;
      }
    }
  }

  ll query(ll x, ll y) {
    ll sum = 0;
    for (ll i = x; i > 0; i -= lowbit(i)) {
      for (ll j = y; j > 0; j -= lowbit(j)) {
        sum += vec[i][j];
      }
    }
    return sum;
  }
}bit;

ll N, Q, op, startX, startY, endX, endY, mp[MAXN][MAXN];

void solve() {
  char c;
  cin >> N >> Q;
  for (ll i = 1; i <= N; i++) {
    for (ll j = 1; j <= N; j++) {
      cin >> c;
      if (c == '*') {
        mp[i][j] = 1;
        bit.update(i, j, 1);
      }
      else mp[i][j] = 0;
    }
  }
  for (ll i = 0; i < Q; i++) {
    cin >> op;
    if (op == 1) {
        cin >> startX >> startY;
        if (mp[startX][startY]) bit.update(startX, startY, -1);
        else bit.update(startX, startY, 1);
        mp[startX][startY] ^= 1;
    }
    else {
        cin >> startX >> startY >> endX >> endY;
        ll ans = bit.query(endX, endY) - bit.query(endX, startY - 1) - bit.query(startX - 1, endY) + bit.query(startX - 1, startY - 1);
        cout << ans << "\n";
    }
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

/*

Input:
4 3
.*..
*.**
**..
****
2 2 2 3 4
1 3 3
2 2 2 3 4

Output:
3
4
*/