// refer to: https://github.com/Jonathan-Uy/CSES-Solutions/blob/main/Range%20Queries/Range%20Queries%20and%20Copies.cpp
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
ll v[MAXN], cnt = 0;

struct SegNode {
    SegNode *lc, *rc;
    ll low, high, sum;
    SegNode(ll _low, ll _high, ll _sum) : lc(nullptr), rc(nullptr), low(_low), high(_high), sum(_sum) {}
    SegNode(SegNode *left, SegNode *right) : lc(left), rc(right), sum(0) {
        if(left){
            sum += left->sum;
            low = left->low;
        }
        if(right){
            sum += right->sum;
            high = right->high;
        }
    }
};

SegNode* build(ll l , ll r) {
    if (l == r) return new SegNode(l, r, v[l]);
    ll m = (l + r) / 2;
    return new SegNode(build(l, m), build(m+1, r));
}

SegNode* update(SegNode *node, ll pos, ll val) {
    if (node->low == node->high) return new SegNode(pos, pos, val);
    ll m = (node->low + node->high) / 2;
    if (pos <= m) return new SegNode(update(node->lc, pos, val), node->rc);
    else return new SegNode(node->lc, update(node->rc, pos, val));
}

ll query(SegNode *node, ll l, ll r) {
    if (l > node->high || r < node->low) return 0;
    if (l <= node->low && node->high <= r) return node->sum;
    return query(node->lc, l, r) + query(node->rc, l, r);
}

SegNode* seg[MAXN];

void solve() {
    cin >> N >> Q;
    for (ll i = 1; i <= N; i++) cin >> v[i];
    cnt = 1;
    seg[cnt] = build(1, N);
    cnt++;
    ll op, k, a, b, x;
    for (ll i = 0; i < Q; i++) {
        cin >> op >> k;
        if (op == 1) {
            cin >> a >> x; 
            seg[k] = update(seg[k], a, x);
        }
        else if (op == 2) {
            cin >> a >> b; 
            ll ans = query(seg[k], a, b);
            cout << ans << "\n";
        }
        else {
            seg[cnt] = new SegNode(seg[k]->lc, seg[k]->rc);
            cnt++;
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
5 6
2 3 1 2 5
3 1
2 1 1 5
2 2 1 5
1 2 2 5
2 1 1 5
2 2 1 5

Output:
13
13
13
15
*/