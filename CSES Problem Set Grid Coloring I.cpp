// refer: Erdos-Szekeres Theorem
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
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
const ll INF = 1e18;
const ll MOD1 = 1e9+7;
const ll MOD2 = 998244353;
 
ll fpow(ll a, ll b, ll m)
{
    if(!b) return 1;
    ll tmp = 1;
    for(ll cur = a; b; b >>= 1, cur = cur * cur % m) if(b & 1) tmp = tmp * cur % m;
    return tmp;
}
ll inv(ll a, ll m) {return fpow(a, m - 2, m);}
 
#define fastio ios::sync_with_stdio(false), cin.tie(0);
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define sz(a) (int) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define per(i, a, b) for (ll i = (a); i >= (b); --i)
#define lowbit(x) x&(-x)
#define vi vector<int>

const ll MAXN = 5e2 + 5;
 
int N, M;
char mp[MAXN][MAXN], ans[MAXN][MAXN];
char c[4] = {'A', 'B', 'C', 'D'};

// ll ask(int a,int b,int c){
  
// }
 
// void ans(ll x, ll y, ll z) {
  
// }

void solve() {
    cin >> N >> M;
    for (ll i = 1; i <= N; i++) {
        string s;
        cin >> s;
        // cout << s << "\n";
        for (ll j = 1; j <= M; j++) {
            mp[i][j] = s[j - 1];
        }
    }
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= M; j++) {
            for (ll k = 0; k < 4; k++) {
                if (c[k] != mp[i][j] and c[k] != ans[i-1][j] and c[k] != ans[i][j - 1]) {
                    ans[i][j] = c[k];
                    break;
                }
            }
        }
    }
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= M; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
 
signed main() {
	fastio int T = 1;
	// cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}
 
/*
0. WA1 -> multiple input
1. WA7 -> specify mod, and use mod or not
*/