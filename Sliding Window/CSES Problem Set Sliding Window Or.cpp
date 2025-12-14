// refer: https://codeforces.com/blog/entry/142846, chunking method
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
 
const ll MAXN = 1e7 + 5;
 
ll N, K, x[MAXN], pre[MAXN], suf[MAXN];
 
// ll ask(int a,int b,int c){
  
// }
 
// void ans(ll x, ll y, ll z) {
  
// }
 
void solve() {
	cin >> N >> K;
    int a, b, c;
    cin >> x[1] >> a >> b >> c;
    for (int i = 2; i <= N; i++) {
        x[i] = x[i-1] * a + b;
        x[i] %= c;
    }
    for (int i = 1; i <= N; i += K) {
        for (int j = i; j < i + K and j <= N; j++) {
            if (j == i) pre[j] = x[j];
            else pre[j] = pre[j - 1] | x[j];
        }
        for (int j = min(N, i + K - 1); j >= i; j--) {
            if (j == min(N, i + K - 1)) suf[j] = x[j];
            else suf[j] = suf[j + 1] | x[j];
        }
    }
    ll sliding_or = 0, ans_xor = 0;
    for (ll i = K; i <= N; i++) {
        sliding_or = pre[i] | suf[i - K + 1];
        ans_xor ^= sliding_or;
    }
    cout << ans_xor << "\n";
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