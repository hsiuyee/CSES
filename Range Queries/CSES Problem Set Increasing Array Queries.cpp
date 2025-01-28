// refer to: https://hackmd.io/@Viecon-342524/HkpEYVnPp#Polynomial-Queries, https://usaco.guide/problems/cses-2416-increasing-array-queries/solution?lang=cpp
// idea1: use stack
// idea2: use "Binary Lifting" to speed up
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
const ll MOD = 998244353;

ll N, Q, v[MAXN], pre[MAXN], a, b, lca[20][MAXN], val[20][MAXN];

void preprocess() {
    cin >> N >> Q;
    for (ll i = 0; i < N; i++) cin >> v[i];
    for (ll i = 0; i < N; i++) {
        if (i == 0) pre[i] = v[i];
        else pre[i] = pre[i - 1] + v[i];
    }
    v[N] = INF;
    lca[0][N] = N;
    vector<ll> suf_num;
    suf_num.push_back(N);
    for (ll i = N-1; i >= 0; i--) {
        while (suf_num.size() and v[i] >= v[suf_num.back()]) {
            suf_num.pop_back();
        }
        lca[0][i]= suf_num.back();
        val[0][i] = (lca[0][i] - i) * v[i];
        suf_num.push_back(i);
    }
    for (ll i = 1; i < 20; i++) {
        for (ll j = 0; j <= N; j++) {
            lca[i][j] = lca[i-1][lca[i-1][j]];
            val[i][j] = val[i-1][j] + val[i-1][lca[i-1][j]];
        }
    }
}

void solve() {
    preprocess();
    for (ll i = 0; i < Q; i++) {
        cin >> a >> b;
        a--;
        b--;
        ll pre_sum;
        if (a != 0) pre_sum = (pre[b] - pre[a-1]);
        else pre_sum = pre[b];
        ll pos = a;
        ll ans = 0;
        for (ll k = 19; k >= 0; k--) {
            if (lca[k][pos] <= b) {
                ans += val[k][pos];
                pos = lca[k][pos];
            }
        }
        ans += (b - pos + 1) * v[pos];
        ans -= pre_sum;
        cout << ans << "\n";
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
2 10 4 2 5
3 5
2 2
1 4

Output:
2
0
14
*/
