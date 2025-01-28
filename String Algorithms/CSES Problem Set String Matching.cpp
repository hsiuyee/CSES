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

struct Hasher {
    static const uint64_t mod = 998244353, p = 131;
    vector<uint64_t> pow_p, h;
    Hasher (const string &s) : pow_p(1, 1), h(s.size()+1, 0) {
        while (pow_p.size() <= s.size()) {
            pow_p.push_back(pow_p.back() * p % mod);
        }
        for (ll i = 0; i < (ll)s.size(); i++) {
            h[i + 1] = (h[i] * p +(uint64_t)s[i]) % mod;
        }
    } // h[i] : 長度為 i 前綴的 hash
    uint64_t get_hash(ll l, ll r) { // 0-base
        return (h[r+1] - h[l] * pow_p[r-l+1] % mod + mod) % mod;
    }
};

ll count_match(const string &T, const string &P) {
    ll ans = 0, n = (ll)P.size();
    Hasher h(T);
    uint64_t h_P = Hasher(P).get_hash(0, n-1); // 語法
    for (ll i = 0; i + n - 1 < (ll)T.size(); i++) {
        ans += (h.get_hash(i, i + n - 1) == h_P);
    }
    return ans;
}

void solve() {
    string T, P;
    cin >> T >> P;
    cout << count_match(T, P) << "\n";
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
