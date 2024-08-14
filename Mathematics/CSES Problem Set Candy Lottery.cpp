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
#include <iomanip>
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


const ll MAXN = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll a[MAXN], N, K;
void solve() {
  long double ans = 0.0;
  cin >> N >> K;
  for(ll i = 1; i <= K; i++){
    long double t1 = pow(i / (long double)K, N);
    long double t2 = pow((i - 1) / (long double)K, N);
    ans += (t1 - t2) * i;
  }
  cout << fixed << setprecision(6) << ans;
}
 
signed main() {
  // fastio 
  ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
