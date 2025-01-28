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
	ll sum_add, sum_minius;
    node(ll x = 0) : sum_add(x), sum_minius(x) {}
    node(long long sum_add, ll sum_minius) : sum_add(sum_add), sum_minius(sum_minius) {}
    friend node operator+(const node &a, const node &b) {
		return {min(a.sum_add, b.sum_add), min(a.sum_minius, b.sum_minius)};
	}
};

struct Segtree {
    node seg[MAXN * 4];
    void build(ll id, ll l, ll r, vector<ll> &v) {
        if (l == r) {
            seg[id] = node(v[l] + l, v[l] - l);
            // cout << "test0: " << l << " " << r << " " << seg[id].sum_add << " " << seg[id].sum_minius << "\n";
            return;
        }
        ll m = (l + r) / 2;
        build(L(id), l, m, v);
        build(R(id), m+1, r, v);
        seg[id] = seg[L(id)] + seg[R(id)];
        // cout << "test0: " << l << " " << r << " " << seg[id].sum_add << " " << seg[id].sum_minius << "\n";
    }
    void single_update(ll id, ll l, ll r, ll pos, ll val) {
        if (l == r) {
            seg[id] = node(val + l, val - l);
            return;
        }
        ll m = (l + r) / 2;
        if (pos <= m) single_update(L(id), l, m, pos, val);
        else single_update(R(id), m + 1, r, pos, val);
        seg[id] = seg[L(id)] + seg[R(id)];
    }
    node query(ll id, ll l, ll r,ll ql, ll qr) {
        if(r < ql || l > qr) return node(INF, INF);
        if (ql <= l && r <= qr) {
            // cout << "test1 in : " << l << " " << r << " " << seg[id].sum_add << " " << seg[id].sum_minius << "\n";
            return seg[id];
        }
        ll m = (l + r) / 2;
        node q1 = query(L(id), l, m, ql, qr);
        node q2 = query(R(id), m+1, r, ql, qr);
        node ans(q1 + q2);
        // cout << "test1 q1: " << l << " " << m << " " << q1.sum_add << " " << q1.sum_minius << "\n";
        // cout << "test1 q2: " << l << " " << m+1 << " " << q2.sum_add << " " << q2.sum_minius << "\n";
        return ans;
    }
}segtree;

ll N, Q, a[MAXN], x, y;

void solve() {
    cin >> N >> Q;
    vector<ll> v(N+1);
    ll x, y, z;
    for (ll i = 1; i <= N; i++) cin >> v[i];
    // cout << "www\n";
    segtree.build(1, 1, N, v);
    for (ll i = 0; i < Q; i++) {
        cin >> x;
        if (x == 1) {
            cin >> y >> z;
            segtree.single_update(1, 1, N, y, z);
        }
        else {
            cin >> y;
            ll ans = segtree.query(1, 1, N, 1, y).sum_minius + y;
            ans = min(ans, segtree.query(1, 1, N, y+1, N).sum_add - y);
            // cout << "consider left: " << (segtree.query(1, 1, N, 1, y).sum_minius) << "\n";
            // cout << "consider right: " << (segtree.query(1, 1, N, y+1, N).sum_add) << "\n";
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
6 3
8 6 4 5 7 5
2 2
1 5 1
2 2

Output:
5
4
*/

/*
6 1
8 6 4 5 7 5
2 2
*/