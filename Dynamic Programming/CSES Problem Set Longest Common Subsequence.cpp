#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <numeric>
#include <unordered_map>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e18;
const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

ll fpow(ll a, ll b, ll m)
{
    if(!b) return 1;
    ll tmp = 1;
    for(ll cur = a; b; b >>= 1, cur = cur * cur % m) if(b & 1) tmp = tmp * cur % m;
    return tmp;
}
ll inv(ll a, ll m) {return fpow(a, m - 2, m);}

#define fastio ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, n)  for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i <= n; i++)
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define sz(a) (ll) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, n) for (ll i = 1; i <= n; i++)
#define lowbit(x) x&(-x)

const ll MAXN = 1e3 + 5;

ll N, M, a[MAXN], b[MAXN], dp[MAXN][MAXN];

// ll ask(int a,int b,int c){
  
// }

// void ans(ll x, ll y, ll z) {
  
// }

void solve() {
    cin >> N >> M;
    for (ll i = 1; i <= N; i++) cin >> a[i];
    for (ll i = 1; i <= M; i++) cin >> b[i];
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= M; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    vector<ll> ans;
    ll l = N, r = M;
    while (l >= 1 and r >= 1) {
        if (a[l] == b[r]) {
            ans.push_back(a[l]);
            l--;r--;
        }
        else if (dp[l - 1][r] > dp[l][r - 1]) l--;
        else r--;
    }
    reverse(all(ans));
    cout << dp[N][M] << "\n";
    for (auto it : ans) cout << it << " ";
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
0. WA1 -> multiple input
1. WA7 -> specify mod, and use mod or not
*/