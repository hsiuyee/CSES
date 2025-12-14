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
 
int N, K, x[MAXN];
map<ll, ll> freq;
map<ll, set<ll> > freq_num;
 
// ll ask(int a,int b,int c){
  
// }
 
// void ans(ll x, ll y, ll z) {
  
// }
 
void cleanup(int f) {
    if (freq_num.count(f) && freq_num[f].empty()) {
        freq_num.erase(f);
    }
}
 
void add(ll val) {
    if (val > K) return;
    ll old_freq = freq[val];
    ll new_freq = old_freq + 1;
    freq[val] = new_freq;
    freq_num[old_freq].erase(val);
    cleanup(old_freq);
    freq_num[new_freq].insert(val);
}
 
void remove(ll val) {
    if (val > K) return;
    ll old_freq = freq[val];
    ll new_freq = old_freq - 1;
    freq[val] = new_freq;
    freq_num[old_freq].erase(val);
    cleanup(old_freq);
    freq_num[new_freq].insert(val);
}
 
ll qry() {
    return *freq_num.begin()->second.begin();
}
 
void solve() {
	cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> x[i];
    map<ll, ll> cnt;
    int sliding_cnt = 0;
    vector<int> ans;
    for (int i = 0; i <= K; i++) {
        freq[i] = 0;
        freq_num[0].insert(i);
    }
    for (int i = 1; i <= N; i++) {
        add(x[i]);
        if (i >= K + 1) remove(x[i - K]);
        if (i >= K) ans.push_back(qry());
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