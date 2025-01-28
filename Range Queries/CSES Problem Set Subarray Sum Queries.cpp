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
#define L(id) 2*id
#define R(id) 2*id+1
#define sz(a) (ll) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, n) for (ll i = 1; i <= n; i++)
#define lowbit(x) x&(-x)
 
const ll MAXN = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1234567891;
const ll P = 989898989;
 
struct node {
	ll mx, pref_mx, suf_mx, sum;
    node(ll x = 0) : mx(max(0LL, x)), pref_mx(max(0LL, x)), suf_mx(max(0LL, x)), sum(x) {}
    node(ll mx, ll pref_mx, ll suf_mx, ll sum) : mx(mx), pref_mx(pref_mx), suf_mx(suf_mx), sum(sum)  {}
    friend node operator+(const node &a, const node &b) {
		return {max({a.mx, b.mx, a.suf_mx + b.pref_mx}), max(a.pref_mx, a.sum + b.pref_mx), max(b.suf_mx, a.suf_mx + b.sum), a.sum + b.sum};
	}
};
 
struct Segtree {
    node seg[MAXN * 4];
    void build(ll id, ll l, ll r, vector<ll> &v) {
        if (l == r) {
            seg[id] = node(v[l]);
            return;
        }
        ll m = (l + r) / 2;
        build(L(id), l, m, v);
        build(R(id), m+1, r, v);
        seg[id] = seg[L(id)] + seg[R(id)];
    }
    void single_update(ll id, ll l, ll r, ll pos, ll val) {
        if (l == r) {
            seg[id] = node(val);
            return;
        }
        ll m = (l + r) / 2;
        if (pos <= m) single_update(L(id), l, m, pos, val);
        else single_update(R(id), m+1, r, pos, val);
        seg[id] = seg[L(id)] + seg[R(id)];
    }
    node query(ll id,ll ql, ll qr, ll l, ll r) {
        if(r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return seg[id];
        ll m = (l + r) / 2;
        node q1 = query(L(id), ql, qr, l, m);
        node q2 = query(R(id), ql, qr, m+1, r);
        return q1 + q2;
    }
}segtree;
 
ll N, Q, a[MAXN], k, x;
 
void solve() {
    cin >> N >> Q;
    vector<ll> v(N+1);
    for (ll i = 1; i <= N; i++) cin >> v[i];
    segtree.build(1, 1, N, v);
    for (ll i = 0; i < Q; i++) {
        cin >> k >> x;
        segtree.single_update(1, 1, N, k, x);
        cout << segtree.query(1, 1, N, 1, N).mx << "\n";
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
5 3
1 2 -3 5 -1
2 6
3 1
2 -2

Output:
9
13
6
*/
