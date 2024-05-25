#include <algorithm>
// #include <bits/stdc++.h>
#include <deque>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <set>
#include <map>
#include <tuple>
#include <vector>
#include <string>
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
 
const ll MAXN = 1e2 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, a, b;
double dp[MAXN][6 * MAXN];

void solve(){
    cin >> N >> a >> b;
    for(ll i = 1; i <= 6; i++) dp[1][i] = 1.0 / 6.0;
    for(ll i = 2; i <= N; i++){
        for(ll j = 2; j <= 600; j++){
            for (ll k = 1; k <= 6; k++) {
                if(j - k >= 0) dp[i][j] += dp[i-1][j-k] / 6.0;
            }
        }
    }
    double ans = 0;
    for (ll i = a; i <= b; i++) {
        ans += dp[N][i];
    }
    printf("%.6f", ans);
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}