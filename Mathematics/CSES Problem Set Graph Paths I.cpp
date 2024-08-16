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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, M, K;
 
vector<vector<ll> > mat(vector<vector<ll> > &x, vector<vector<ll> > &y) {
    vector<vector<ll> > ret(N, vector<ll>(N, 0));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            for (ll k = 0; k < N; k++) { 
                ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD; 
            }
        }
    }
    return ret;
}
 
vector<vector<ll> > mpow(vector<vector<ll> > x, ll y, vector<vector<ll> > I) {
    if (y == 0) return I;
    else if (y == 1) return x;
    vector<vector<ll> > ret(N, vector<ll>(N, 0));
    vector<vector<ll> > tmp = mpow(x, y / 2, I);
    ret = mat(tmp, tmp);
    if (y % 2 == 1) ret = mat(ret, x);
    return ret;
}
void solve() {
    cin >> N >> M >> K;
    ll a, b;
    vector<vector<ll> > G(N, vector<ll>(N, 0));
    for(ll i = 0; i < M; i++){
        cin >> a >> b;
        a--;
        b--;
        G[a][b]++;
    }
    vector<vector<ll> > I(N, vector<ll>(N, 0));
    for(ll i = 0; i < N; i++) I[i][i] = 1;
    vector<vector<ll> > ans = mpow(G, K, I);
    cout << ans[0][N - 1] << "\n";
}
 
signed main() {
    fastio ll T = 1;
    // cin >> T;
    for (ll i = 1; i <= T; i++) {
    solve();
    }
    return 0;
}