#include <algorithm>
// #include <bits/stdc++.h>
// #include <deque>
// #include <queue>
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

const ll MAXN = 4e5 + 5;
// const ll MAXM = 500 * 501 / 4 + 5;
// const ll INF = 1e18;
// const ll MOD = 1e9 + 7;

struct info {
  ll s, e, v;
};

bool cmp(info a, info b) {
  if (a.s == b.s)
    return a.e < b.e;
  else
    return a.s < b.s;
}

ll N, dp[MAXN];
info a[MAXN]; // 0~N 天的最大收益

void solve() {
  dp[0] = 0;
  cin >> N;
  vector<ll> num;
  rep(i, N) {
    cin >> a[i].s >> a[i].e >> a[i].v;
    num.push_back(a[i].s);
    num.push_back(a[i].e);
  }
  sort(all(num));
  num.resize(unique(all(num)) - num.begin());
  rep(i, N) {
    a[i].s = lower_bound(all(num), a[i].s) - num.begin() + 1;
    a[i].e = lower_bound(all(num), a[i].e) - num.begin() + 1;
  }
  sort(a + 1, a + 1 + N, cmp);
  ll last = 0, ans = 0;
  rep(i, N) {
    while (last < a[i].s - 1) {
      last++;
      dp[last] = max(dp[last - 1], dp[last]);
    }
    dp[a[i].e] = max(dp[a[i].e], dp[a[i].s - 1] + a[i].v);
    // cout << a[i].e << " " << dp[a[i].e] << "\n";
    ans = max(ans, dp[a[i].e]);
  }
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
