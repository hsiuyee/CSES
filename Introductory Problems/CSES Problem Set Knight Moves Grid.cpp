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

const ll MAXN = 1e3 + 5;
 
int N, M;
int dp[MAXN][MAXN], vis[MAXN][MAXN];
int dx[8] = {1, 1, -1, -1, 2, -2, 2, -2};
int dy[8] = {2, -2, 2, -2, 1, 1, -1, -1};

// ll ask(int a,int b,int c){
  
// }
 
// void ans(ll x, ll y, ll z) {
  
// }

bool isVaild(ll x, ll y) {
    return 0 <= x and x < N and 0 <= y and y < N and !vis[x][y];
}

void solve() {
    cin >> N;
    queue<pll> qu;
    qu.push(mkp(0, 0));
    vis[0][0] = true;
    dp[0][0] = 0;
    while (qu.size()) {
        ll x = qu.front().first;
        ll y = qu.front().second;
        qu.pop();
        for (ll i = 0; i < 8; i++) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (isVaild(nx, ny)) {
                vis[nx][ny] = true;
                dp[nx][ny] = dp[x][y] + 1;
                qu.push(mkp(nx, ny));
            }
        }
    }
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cout << dp[i][j] << " ";
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