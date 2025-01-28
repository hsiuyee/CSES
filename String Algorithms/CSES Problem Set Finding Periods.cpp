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

const ll MAXN = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

// f[i] = max j s.t. j <= i and s[0, j-1] = s[i-j+1, i]
vector<ll> fail_function(const string &s) {
    ll n = (ll) s.size();
    vector<ll> f(n);
    for (ll i = 1; i < n; i++) {
        ll j = f[i - 1];
        while (j > 0 and s[j] != s[i]) j = f[j-1];
    }
}
void solve() {
    
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
