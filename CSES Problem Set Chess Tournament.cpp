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
	cin >> N;
    for (ll i = 1; i <= N; i++) cin >> x[i];
    priority_queue<pll, vector<pll>, less<pll> > pq;
    ll sum_deg = 0;
    for (ll i = 1; i <= N; i++) {
        sum_deg += x[i];
        if (x[i] > 0) pq.push(mkp(x[i], i));
        if (x[i] >= N) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    if (sum_deg % 2 != 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<pll> ans;
    while (pq.size()) {
        ll deg = pq.top().first;
        ll id = pq.top().second;
        pq.pop();
        if (deg == 0) continue;
        if (deg > sz(pq)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        vector<pll> recover;
        for (ll i = 0; i < deg; i++) {
            ll deg_t = pq.top().first;
            ll id_t = pq.top().second;
            pq.pop();
            ans.push_back(mkp(id, id_t));
            if (deg_t > 1) recover.push_back(mkp(deg_t - 1, id_t));
        }
        for (auto it : recover) pq.push(it);
    }
    cout << sz(ans) << "\n";
    for (auto it : ans) cout << it.first << " " << it.second << "\n";
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