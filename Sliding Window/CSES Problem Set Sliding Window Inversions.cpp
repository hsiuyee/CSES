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
 
const ll MAXN = 2e5 + 5;
 
int N, K, x[MAXN], bit[MAXN];
ll sum;
map<ll, ll> freq;
map<ll, set<ll> > freq_num;

// ll ask(int a,int b,int c){
  
// }
 
// void ans(ll x, ll y, ll z) {
  
// }

void upd(ll i, ll v) {
    for (; i < MAXN; i += lowbit(i)) bit[i] += v;
}

ll qry(ll i) {
    ll rev = 0;
    for (; i > 0; i -= lowbit(i)) rev += bit[i];
    return rev;
}

void add(ll v) {
    sum += qry(MAXN-1) - qry(v);
    upd(v, 1);
}

void remove(ll v) {
    upd(v, -1);
    if (v > 1) sum -= qry(v - 1);
    
}

void solve() {
	cin >> N >> K;
    vector<ll> vec;
    for (int i = 1; i <= N; i++) {
        cin >> x[i];
        vec.push_back(x[i]);
    }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    for (int i = 1; i <= N; i++) {
        x[i] = lower_bound(all(vec), x[i]) - vec.begin() + 1;
    }
    sum = 0;
    vector<ll> ans;
    for (int i = 1; i <= N; i++) {
        add(x[i]);
        if (i >= K + 1) remove(x[i - K]);
        if (i >= K) ans.push_back(sum);
    }
    for (auto it : ans) cout << it << " ";
    
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