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

const ll MAXN = 2e5 + 5;
vector<ll> G[MAXN];
vector<ll> GT[MAXN];
ll N, M, vis[MAXN], color[MAXN], indeg[MAXN];
vector<ll> v; // build order
ll scc, sz[MAXN], dp[MAXN];

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
    vector<ll> toposort;
    queue<ll> qu;
    for (ll i = 1; i < scc; i++) {
        if (indeg[i] == 0) {
            qu.push(i);
        }
        dp[i] = sz[i];
    }
    
    while (sz(qu)) {
        ll u = qu.front();
        qu.pop();
        toposort.push_back(u);
        for (auto v : Gnew[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                qu.push(v);
            }
        }
    }
    for (auto u : toposort) {
        for (auto v : Gnew[u]) {
            dp[v] += dp[v];
        }
    }
    for (ll i = 1; i <= N; i++) {
        cout << dp[color[i]] << " ";
    }
}

void build_new_graph() {
    for (ll i = 1; i <= N; i++) {
        sz[color[i]]++;
        // cout << i << " color " << color[i] << "\n";
    }
    // for (ll i = 1; i < scc; i++) cout << "scc: " << i << " " << sz[i] << "\n";
    for (ll i = 1; i <= N; i++) {
        for (auto it : G[i]) {
            pll p = mkp(color[i], color[it]);
            if (p.F == p.S || mp[p]) continue;
            mp[p] = true;
            Gnew[p.S].push_back(p.F);
            indeg[p.F]++;
        }
    }
}

void solve() {
	cin >> N;
    ll a;
    scc = 1;
    for (ll i = 1; i <= N; i++) {
        cin >> a;
        G[i].push_back(a);
        GT[a].push_back(i);
    }
    for (ll i = 1; i <= N; i++) {
        if(!vis[i]) dfs(i);
    }
    for (ll i = sz(v) - 1ll; i >= 0; i--) {
        if(!color[v[i]]){
            dfsscc(v[i]);
            scc++;
        }
    }
    build_new_graph();
    ans();
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