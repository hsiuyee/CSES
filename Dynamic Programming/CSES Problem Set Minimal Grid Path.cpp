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

const ll MAXN = 3e3 + 5;

ll N, M;
string mp[MAXN], dp[MAXN][MAXN];

// ll ask(int a,int b,int c){
  
// }

// void ans(ll x, ll y, ll z) {
  
// }

void solve() {
    cin >> N;
    for (ll i = 0; i < N; i++) {
        cin >> mp[i];
        // cout << i << " " << N << mp[i] << "\n";
    }
    ll update = 0;
    for (ll j = 0; j < N; j++) dp[update ^ 1][j] = INF;
    dp[0][0] = mp[0][0];
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (i > 0 and j == 0) {
                dp[update][j] = dp[update ^ 1][j] + mp[i][j];
            }
            if (i == 0 and j > 0) dp[update][j] = dp[update][j - 1] + mp[i][j];
            else if (i > 0 and j > 0) {
                if (dp[update ^ 1][j] > dp[update][j - 1]) dp[update][j] = dp[update][j - 1] + mp[i][j];
                else dp[update][j] = dp[update ^ 1][j] + mp[i][j];
            }
            // cout << dp[update][j] << " ";
        }
        update ^= 1;
        // cout << "\n";
    }
    cout << dp[update ^ 1][N - 1] << "\n";
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

4
AACA
BABC
ABDA
AACA
*/