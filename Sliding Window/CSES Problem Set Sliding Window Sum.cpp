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
 
ll N, K, x[MAXN];
 
// ll ask(int a,int b,int c){
  
// }
 
// void ans(ll x, ll y, ll z) {
  
// }
 
void solve() {
    vector<ll> ans;
	cin >> N >> K;
    ll a, b, c;
    cin >> x[1] >> a >> b >> c;
    for (ll i = 2; i <= N; i++) {
        x[i] = x[i-1] * a + b;
        x[i] %= c;
        // cout << "x[i]: " << x[i] << "\n";
    }
    queue<pll> qu;
    ll sum = 0;
    for (ll i = 1; i <= N; i++) {
        while (qu.size() and i - qu.front().first >= K) {
            pll element = qu.front();
            sum -= element.second;
            qu.pop();
        }
        qu.push(mkp(i, x[i]));
        sum += x[i];
        if (sz(qu) == K) ans.push_back(sum);
    }
    ll ans_xor = 0;
    for (auto it : ans) ans_xor ^= it;
    cout << ans_xor << "\n";
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