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
 
const ll MAXN = 2e3 + 5;
const ll INF = 4e18;
const ll MOD = 1e9 + 7;
 
typedef vector<ll> vll;
ll N, M, K;
 
vector<vector<ll> > mat(const vector<vector<ll> > &x, const vector<vector<ll> > &y) {
    vector<vector<ll> > ret(N, vector<ll>(N, INF));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            for (ll k = 0; k < N; k++) { 
                ret[i][j] = min(ret[i][j], x[i][k] + y[k][j]);
            }
        }
    }
    return ret;
}
 
vector<vector<ll> > mpow(vector<vector<ll> > x, ll y) {
    if (y == 1) return x;
    vector<vector<ll> > ret = mpow(x, y / 2);
    ret = mat(ret, ret);
    if (y % 2 == 1) ret = mat(ret, x);
    return ret;
}

void solve() {
    cin >> N >> M >> K;
    ll a, b, c;
    vector<vector<ll> > G(N, vector<ll>(N, INF));
    for(ll i = 0; i < M; i++){
        cin >> a >> b >> c;
        a--;
        b--;
        G[a][b] = min(G[a][b], c);
    }
    vector<vector<ll> > I(N, vector<ll>(N, INF));
    vector<vector<ll> > ans = mpow(G, K);
    if( ans[0][N - 1] == INF) cout << "-1\n";
    else cout << ans[0][N - 1] << "\n";
}
 
signed main() {
    fastio ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++) {
        solve();
    }
    return 0;
}
