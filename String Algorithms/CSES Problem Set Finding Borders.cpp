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

const ll MAXN = 1e6 + 5;

int N;
string s;

// ll ask(int a,int b,int c){
  
// }

// void ans(ll x, ll y, ll z) {
  
// }

vi Z(const string& S) {
	vi z(sz(S));
	int l = -1, r = -1;
	for (int i = 1; i < sz(S); i++) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

void solve() {
    string s;
    cin >> s;
    N = sz(s);
    vi v = Z(s);
    for (ll i = N - 1; i >= 1; i--) {
        if (v[i] == N - i) cout << N - i << " ";
    }
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