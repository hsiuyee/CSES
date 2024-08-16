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
 
ll N;
 
vector<ll> vec[2];
vector<vector<ll> > I(6, vector<ll>(6, 0));
 
vector<vector<ll> > mat(vector<vector<ll> > &x, vector<vector<ll> > &y) {
  vector<vector<ll> > ret(6, vector<ll>(6, 0));
  for (ll i = 0; i < 6; i++) {
    for (ll j = 0; j < 6; j++) {
      for (ll k = 0; k < 6; k++) { 
        ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD; 
      }
    }
  }
  return ret;
}
 
vector<vector<ll> > mpow(vector<vector<ll> > x, ll y) {
  if (y == 0) return I;
  else if (y == 1) return x;
  vector<vector<ll> > ret(6, vector<ll>(6, 0));
  vector<vector<ll> > tmp = mpow(x, y / 2);
  ret = mat(tmp, tmp);
  if (y % 2 == 1) ret = mat(ret, x);
  return ret;
}
void solve() {
  cin >> N;
  vector<vector<ll> > m(6, vector<ll>(6, 0));
  m[1][0] = m[2][1] = m[3][2] = m[4][3] = m[5][4] = 1;
  for(ll i = 0; i < 6; i++){
    m[0][i] = 1;
  }
  // for(ll i = 0; i < 6; i++){
  //   for(ll j = 0; j < 6; j++){
  //     cout << m[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  vector<vector<ll> > ans = mpow(m, N + 6); // +6: initial state need
  // cout << "\n";
  // for(ll i = 0; i < 6; i++){
  //   for(ll j = 0; j < 6; j++){
  //     cout << ans[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  cout << ans[5][5] << "\n";
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
