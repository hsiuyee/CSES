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
#define F first
#define S second
#define mkp make_pair
#define sz(a) (ll) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define per(i, a, b) for (ll i = (a); i >= (b); --i)
#define lowbit(x) x&(-x)
#define vi vector<int>

const ll MAXN = 1e5 + 5;
vector<ll> G[MAXN];
vector<ll> GT[MAXN];
ll N, M, vis[MAXN], color[MAXN], indeg[MAXN];
vector<ll> v; // build order
ll scc, coin[MAXN], newcoin[MAXN], dp[MAXN];

void dfs(ll a) {
    vis[a] = 1;
    for(auto it : G[a]) {
        if(!vis[it]){
            vis[it] = 1;
            dfs(it);
        }
    }
    v.push_back(a);
}

void dfsscc(ll a) {
    color[a] = scc;
    for(auto it : GT[a]) {
        if(!color[it]){
            color[it] = scc;
            dfsscc(it);
        }
    }
}


vector<ll> Gnew[MAXN];
map<pll, bool> mp;

ll ans() {
    ll rev = 0;
    queue<ll> qu;
    for (ll i = 1; i < scc; i++) {
        if (indeg[i] == 0) {
            qu.push(i);
            dp[i] = newcoin[i];
        }
    }
    while (qu.size()) {
        ll t = qu.front();
        rev = max(rev, dp[t]); // one-point edge case
        qu.pop();
        for (auto it : Gnew[t]) {
            dp[it] = max(dp[it], dp[t] + newcoin[it]);
            indeg[it]--;
            if (indeg[it] == 0) {
                qu.push(it);
            }
        }
    }
    return rev;
}

void build_new_graph() {
    for (ll i = 1; i <= N; i++) {
        newcoin[color[i]] += coin[i];
    }
    for (ll i = 1; i <= N; i++) {
        for (auto it : G[i]) {
            pll p = mkp(color[i], color[it]);
            if (p.F == p.S || mp[p]) continue;
            mp[p] = true;
            Gnew[p.F].push_back(p.S);
            indeg[p.S]++;
        }
    }
}

void solve() {
	cin >> N >> M;
    ll a, b;
    scc = 1;
    for (ll i = 1; i <= N; i++) cin >> coin[i];
    for (ll i = 1; i <= M; i++){
        cin >> a >> b;
        G[a].push_back(b);
        GT[b].push_back(a);
    }
    for (ll i = 1; i <= N; i++) {
        if(!vis[i]) dfs(i);
    }
    for (ll i = sz(v) - 1ll; i >= 0; i--){
        if(!color[v[i]]){
            dfsscc(v[i]);
            scc++;
        }
    }
    build_new_graph();
    cout << ans() << "\n";
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