#include <algorithm>
// #include <bits/stdc++.h>
// #include <deque>
#include <queue>
// #include <cmath>
#include <iostream>
// #include <stdio.h>
#include <set>
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

const ll MAXN = 500 + 5;
const ll MAXM = 500 * 501 / 4 + 5;
// const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll N, a[MAXN], dp[MAXM + 5];

ll fastpow(ll a, ll p) {
  if (p == 0)
    return 1;
  if (p == 1)
    return a;
  ll t = a * a % MOD;
  if (p % 2 == 0)
    return fastpow(t, p / 2);
  else
    return (a * fastpow(t, p / 2)) % MOD;
}

ll inv(ll a, ll p) { return fastpow(a, p - 2); }

void solve() {
  dp[0] = 1;
  cin >> N;
  rep(i, N) a[i] = i;
  rep(i, N) {
    for (ll j = MAXM - 1; j >= a[i]; j--) {
      dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
    }
  }
  // for (ll i = 0; i <= N * (N + 1) / 2; i++)
  //   cout << i << " " << dp[i] << "\n";
  if (N * (N + 1) % 4 != 0) {
    cout << 0 << "\n";
    return;
  }
  cout << (dp[N * (N + 1) / 4] % MOD) * inv(2, MOD) % MOD << '\n';
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}