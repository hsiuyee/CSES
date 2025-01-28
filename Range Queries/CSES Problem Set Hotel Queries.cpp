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
 
const ll MAXN = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1234567891;
const ll P = 989898989;
 
ll N, Q, a, b, x, y;
 
struct SegTree {
  ll mx[4 * MAXN];
  void build(ll id, ll l, ll r, vector<ll> &v) {
    if (l == r) {
      mx[id] = v[l];
      return;
    }
    ll m = (l + r) / 2;
    build(id*2, l, m, v);
    build(id*2+1, m+1, r, v);
    mx[id] = max(mx[id*2], mx[id*2+1]);
  }
  void single_update(ll id, ll l, ll r, ll pos, ll val) {
    if(r < pos || l > pos) return;
    else if (pos <= l && r <= pos){
        mx[id] += val;
    }
    else{
        ll m = (l + r)/2;
        if (pos <= m) single_update(2 * id, l, m, pos, val);
        else single_update(2 * id + 1, m + 1, r, pos, val);
        mx[id] = max(mx[id * 2], mx[id * 2 + 1]);
    }
  }
  pll range_query(ll id, ll l, ll r, ll val) {
    if (l == r) {
      if (val > mx[id]) return mkp(0, 0);
      else return mkp(l, mx[id]);
    }
    ll m = (l + r) / 2;
    if (mx[id * 2] >= val) return range_query(id * 2, l, m, val);
    else if (mx[id * 2 + 1] >= val) return range_query(id * 2 + 1, m + 1, r, val);
    else return mkp(0, 0);
  }
};
 
void solve() {
  cin >> N >> Q;
  vector<ll> v(N+1);
  for (ll i = 1; i <= N; i++) cin >> v[i];
  SegTree segtree;
  segtree.build(1, 1, N, v);
  for (ll i = 0; i < Q; i++) {
    cin >> x;
    pll p = segtree.range_query(1, 1, N, x);
    if (p.F != 0) segtree.single_update(1, 1, N, p.F, -x);
    cout << p.F << " ";
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
 
