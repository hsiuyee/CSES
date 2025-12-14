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
 
const ll MAXN = 1e2 + 5;
 
ll N, A, B, ans[MAXN][2];
 
// ll ask(int a,int b,int c){
  
// }
 
// void ans(ll x, ll y, ll z) {
  
// }

void solve() {
    cin >> N >> A >> B;
    if (A + B > N or (A > 0 and B == 0) or (A == 0 and B > 0)) {
        cout << "NO\n";
        return;
    }
    // cout << A << " " << B << "\n";
    ll D = N - A - B;
    for (int i = 1; i <= N; i++) ans[i][0] = i;
    for (int i = 1; i <= D; i++) ans[i][1] = i;

    cout << "YES\n";
    ll shift = D;
    for (int i = 1; i <= B; i++) ans[shift + i][1] = D + A + i;
    shift += B;
    for (int i = 1; i <= A; i++) ans[shift + i][1] = D + i;

    for (int i = 1; i <= N; i++) cout << ans[i][0] << " ";
    cout << "\n";
    for (int i = 1; i <= N; i++) cout << ans[i][1] << " ";
}

signed main() {
	fastio int T = 1;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}
 
/*
0. WA1 -> multiple input
1. WA7 -> specify mod, and use mod or not
*/