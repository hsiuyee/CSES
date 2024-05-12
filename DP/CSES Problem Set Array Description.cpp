// #include <algorithm>
// #include <bits/stdc++.h>
// #include <deque>
// #include <queue>
// #include <cmath>
#include <iostream>
// #include <stdio.h>
// #include <set>
// #include <map>
// #include <vector>
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

const ll MAXN = 1e5 + 5;
const ll MAXM = 1e2 + 5;
// const ll MAXM = 500 * 501 / 4 + 5;
// const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll N, M, dp[MAXN][MAXM], arr[MAXN];

ll dx[3] = {1, -1, 0};
bool isVaild(ll x) { return 1 <= x and x <= M; }

void solve() {
  cin >> N >> M;
  rep(i, N) cin >> arr[i];
  rep(i, N) {
    if (i == 1) {
      if (arr[i] == 0)
        for (ll j = 1; j <= M; j++)
          dp[i][j] = 1;
      else
        dp[i][arr[i]] = 1;

    } else {
      if (arr[i] != 0) {
        for (ll j = 0; j < 3; j++)
          if (isVaild(arr[i] + dx[j])) {
            dp[i][arr[i]] = (dp[i - 1][arr[i] + dx[j]] + dp[i][arr[i]]) % MOD;
          }
      } else {
        for (ll k = 1; k <= M; k++)
          for (ll j = 0; j < 3; j++)
            if (isVaild(k + dx[j]))
              dp[i][k] = (dp[i - 1][k + dx[j]] + dp[i][k]) % MOD;
      }
    }
  }
  ll ans = 0;
  for (ll j = 1; j <= M; j++)
    ans = (ans + dp[N][j]) % MOD;
  cout << ans << "\n";
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
