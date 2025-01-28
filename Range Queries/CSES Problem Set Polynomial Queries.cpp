// refer to: https://hackmd.io/@winliu/r1tN512cT
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
#define L(id) (2 * id)
#define R(id) (2 * id + 1)
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define sz(a) (ll) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, n) for (ll i = 1; i <= n; i++)
#define lowbit(x) x&(-x)

const ll MAXN = 1e6 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

ll N, Q;

struct SegTree {
    ll sum[MAXN * 4];
    ll tag_m[MAXN * 4 + 10], tag_k[MAXN * 4 + 10];

    void pull(ll id) {
        sum[id] = sum[L(id)] + sum[R(id)];
    }

    void addTag(ll id, ll l, ll r, ll _m, ll _k) {
        tag_m[id] += _m;
        tag_k[id] += _k;
        ll len = r - l + 1;
        sum[id] += _m * len * (len + 1) / 2;
        sum[id] += _k * len;
    }

    void pushTag(ll id, ll l, ll r) {
        ll m = (l + r) / 2;
        ll shift = (m + 1 - l);
        addTag(L(id), l, m, tag_m[id], tag_k[id]);
        addTag(R(id), m+1, r, tag_m[id], tag_m[id] * shift + tag_k[id]);
        tag_m[id] = tag_k[id] = 0;
    }

    void build(ll id, ll l, ll r, vector<ll> &v) {
        if (l == r) {
            sum[id] = v[l];
            tag_m[id] = tag_k[id] = 0;
            return;
        }
        ll m = (l + r) / 2;
        build(L(id), l, m, v);
        build(R(id), m+1, r, v);
        pull(id);
    }

    void range_update(ll id, ll l, ll r, ll L, ll R) {
        if (L <= l and r <= R) {
            addTag(id, l, r, 1, l - L);
            return;
        }
        pushTag(id, l, r);
        ll m = (l + r) / 2;
        if (L <= m) range_update(L(id), l, m, L, R);
        if (m < R) range_update(R(id), m+1, r, L, R);
        pull(id);
    }

    ll range_query(ll id, ll l, ll r, ll L, ll R) {
        if (l >= L and r <= R) return sum[id];
        pushTag(id, l, r);
        ll m = (l + r) / 2, res = 0;
        if (L <= m) res += range_query(L(id), l, m, L, R);
        if (m < R) res += range_query(R(id), m+1, r, L, R);
        return res;
    }
}segtree;

void solve() {
    cin >> N >> Q;
    vector<ll> v(N+1);
    for (ll i = 1; i <= N; i++) cin >> v[i];
    segtree.build(1, 1, N, v);
    ll op, a, b;
    for (ll i = 0; i < Q; i++) {
        cin >> op >> a >> b;
        if (op == 1) {
            segtree.range_update(1, 1, N, a, b);
        }
        else {
            ll ans = segtree.range_query(1, 1, N, a, b);
            cout << ans << "\n";
        }
    }
}

signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
/*
Input:
5 3
4 2 3 1 7
2 1 5
1 1 5
2 1 5

Output:
17
32
*/