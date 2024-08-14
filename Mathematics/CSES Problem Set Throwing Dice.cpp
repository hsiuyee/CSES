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
 
const ll MAXN = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll a[MAXN], N, pre[MAXN];
 
vector<ll> vec[2];
vector<vector<ll> > I(6, vector<ll>(6, 0));
 
vector<vector<ll> > mat(vector<vector<ll> > &x, vector<vector<ll> > &y) {
  vector<vector<ll> > ret(6, vector<ll>(6, 0));
  rep(i, 6) {
    rep(j, 6) {
      rep(k, 6) { ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD; }
    }
  }
  return ret;
}
 
vector<vector<ll> > mpow(vector<vector<ll> > x, ll y) {
  if (y == 0) {
    return I;
  }
  if (y == 1) {
    return x;
  }
  vector<vector<ll> > ret(6, vector<ll>(6, 0));
  vector<vector<ll> > tmp = mpow(x, y / 2);
  ret = mat(tmp, tmp);
  if (y % 2 == 1)
    ret = mat(ret, x);
  return ret;
}
void solve() {
  cin >> N;
  if(N == 1){
    cout << 1 << "\n";
    return;
  }
  vector<vector<ll> > m(6, vector<ll>(6, 0));
  for(ll i = 0; i < 6; i++) m[0][i] = 1;
  for(ll i = 0; i < 5; i++) m[i+1][i] = 1;
  for(ll i = 0; i < 6; i++){
    for(ll j = 0; j < 6; j++){
      cout << m[i][j] << " ";
    }
    cout << "\n";
  }
  vector<vector<ll> > ans = mpow(m, N);
  ll dp[6][6];
  for(ll i = 0; i < 6; i++) dp[1][i] = 1;
  for(ll i = 0; i < 6; i++){

  }
  // cout << ans[5][4] % MOD << '\n';
  // for(ll i = 0; i < 6; i++){
  //   for(ll j = 0; j < 6; j++){
  //     cout << ans[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
}
 
signed main() {
  fastio ll T = 1;
  // cin >> T;
  for(ll i = 0; i < 6; i++) I[i][i] = 1;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
