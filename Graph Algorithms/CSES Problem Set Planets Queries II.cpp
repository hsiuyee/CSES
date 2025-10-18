// ref: https://usaco.guide/problems/cses-1160-planets-queries-ii/solution
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

const ll MAXN = 2e5 + 5;
const ll MAXLOG = 20;
ll N, Q, nxt[MAXN], dis_to_cycle[MAXN], jump[MAXN][MAXLOG];
ll position_type[MAXN]; // -2: not processed, -1: tree, >= 0: cycle
vector<ll> G[MAXN], before[MAXN];
vector<map<ll, ll> > cycles_id;

void find_cycles_id() {
    for (ll i = 1; i <= N; i++) {
        if (position_type[i] != -2) continue;
        vector<ll> path;
        path.push_back(i);
        ll now = i;
        while (position_type[nxt[now]] == -2) {
            now = nxt[now];
            position_type[now] = -3;
            path.push_back(now);
        }
        map<ll, ll> cycle_id;
        bool in_cycle = false;
        for (auto v : path) {
            in_cycle |= (v == nxt[now]);
            if (in_cycle) cycle_id[v] = sz(cycle_id);
            position_type[v] = in_cycle ? sz(cycles_id) : -1;
        }
        cycles_id.push_back(cycle_id);
    }
}

void cal_dis_to_cycle() {
    for (ll i = 1; i <= N; i++) {
        if (!(position_type[nxt[i]] >= 0 and position_type[i] == -1)) continue;
        dis_to_cycle[i] = 1;
        vector<ll> vec = before[i];
        while (sz(vec)) {
            ll cur = vec.back();
            vec.pop_back();
            dis_to_cycle[cur] = dis_to_cycle[nxt[cur]] + 1;
            vec.insert(vec.end(), before[cur].begin(), before[cur].end());
        }
    }
}

void binary_jump() {
    for (ll i = 1; i <= N; i++) jump[i][0] = nxt[i];
    for (ll j = 1; j < MAXLOG; j++) {
        for (ll i = 1; i <= N; i++) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
}


ll get_jump_point(ll x, ll d) {
    for (ll j = MAXLOG - 1; j >= 0; j--) {
        if ((d & (1 << j)) != 0) x = jump[x][j];
    }
    return x;
}

bool in_the_same_component(ll u, ll v) {
    return (position_type[jump[u][MAXLOG - 1]] == position_type[jump[v][MAXLOG - 1]]);
}

void both_on_tree(ll u, ll v) {
    if (dis_to_cycle[u] < dis_to_cycle[v]) {
        cout << "-1\n";
        return;
    }
    ll dis = dis_to_cycle[u] - dis_to_cycle[v];
    u = get_jump_point(u, dis);
    if (u != v) cout << "-1\n";
    else cout << dis << "\n";
}

void solve() {
	cin >> N >> Q;
    for (ll i = 1; i <= N; i++) {
        cin >> nxt[i];
        before[nxt[i]].push_back(i);
    }
    for (ll i = 1; i <= N; i++) {
        position_type[i] = -2;
    }
    find_cycles_id();
    cal_dis_to_cycle();
    binary_jump();
    while (Q--) {
        ll u, v;
        cin >> u >> v;
        if (!in_the_same_component(u, v)) {
            cout << "-1\n";
            continue;
        }
        if (position_type[u] == -1 and position_type[v] == -1) {
            both_on_tree(u, v);
        }
        else {
            if (position_type[v] == -1 and position_type[u] != -1) {
                cout << "-1\n";
                continue;
            }
            ll dis = dis_to_cycle[u];
            ll u_root = get_jump_point(u, dis);
            map<ll, ll> &cycle_id = cycles_id[position_type[u_root]];
            ll idx1 = cycle_id[u_root];
            ll idx2 = cycle_id[v];
            ll diff = 0;
            if (idx1 <= idx2) diff = idx2 - idx1;
            else diff = sz(cycle_id) - (idx1 - idx2);
            cout << dis + diff << "\n";
        }
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