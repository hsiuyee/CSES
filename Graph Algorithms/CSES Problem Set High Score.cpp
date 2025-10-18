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

const ll INF = 6e12;
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
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define sz(a) (int) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define per(i, a, b) for (ll i = (a); i >= (b); --i)
#define lowbit(x) x&(-x)
#define vi vector<int>

const ll MAXN = 1e5+5;
 
ll n, m, a, b, x;
vector<pll> G[MAXN];
 
void init(){
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		cin >> a >> b >> x;
		G[a].push_back(mkp(b, x));
	}
}
 
void BellmanFord(ll s,ll n) {
    vector<ll> dis(n + 1, -INF);
    dis[s] = 0;
    for (ll i = 1; i <= n-1; i++) {
    	for (ll u = 1; u <= n; u++) {
    		if (dis[u] == -INF) continue;
		    for (auto edge : G[u]) {
		        if (dis[edge.F] < dis[u] + edge.S) {
		            dis[edge.F] = dis[u] + edge.S;
		        }
		    }
		}
    }
    vector<ll> cycle_nodes;
	for (ll u = 1; u <= n; u++) {
        if (dis[u] == -INF) continue;
        for (auto edge : G[u]) {
            if (dis[edge.F] < dis[u] + edge.S) {
                cycle_nodes.push_back(edge.F);
            }
        }
	}
    if (!sz(cycle_nodes)) {
        cout << dis[n] << '\n';
        return;
    }
    vector<bool> vis(n + 1, false);
    queue<ll> qu;
    for (auto v : cycle_nodes) {
        qu.push(v);
        vis[v] = true;
    }
    while (qu.size()) {
        ll t = qu.front();
        qu.pop();
        if (t == n) {
            cout << "-1\n";
            return;
        }
        for (auto e : G[t]) {
            if (!vis[e.F]) {
                vis[e.F] = true;
                qu.push(e.F);
            }
        }
    }
    cout << dis[n] << '\n';
}
 
int main(){
	fastio
	init();
	BellmanFord(1, n);
	return 0;
}