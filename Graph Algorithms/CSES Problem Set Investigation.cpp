// #include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <tuple>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false), cin.tie(0);
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define sz(a) (ll) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, n) for (ll i = 1; i <= n; i++)
#define lowbit(x) x&(-x)

const ll MAXN = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1000000007;

ll N, M;
vector<pll> G[MAXN];
ll dis[MAXN], num[MAXN], minFlights[MAXN], maxFlights[MAXN], relax[MAXN];

void djikstra(ll s) {
    dis[s] = minFlights[s] = maxFlights[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push(pll(dis[s], s));
    num[s] = 1;
    while (pq.size()) {
        ll now = pq.top().S;
        pq.pop();
        if (relax[now]) continue;
        relax[now] = 1;
        for (auto it : G[now]) {
            ll cost = dis[now] + it.F;
            if (cost == dis[it.S]) {
                num[it.S] = (num[it.S] + num[now]) % MOD;
                minFlights[it.S] = min(minFlights[it.S], minFlights[now] + 1);
                maxFlights[it.S] = max(maxFlights[it.S], maxFlights[now] + 1);
            }
            else if (cost < dis[it.S]) {
                dis[it.S] = cost;
                num[it.S] = num[now];
                minFlights[it.S] = minFlights[now] + 1;
                maxFlights[it.S] = maxFlights[now] + 1;
                pq.push(pll(dis[it.S], it.S));
            }
        }
    }
}


void solve() {
  cin >> N >> M;
  string s;
  ll a, b, x;
  for (ll i = 0; i < M; i++) {
    cin >> a >> b >> x;
    G[a].push_back(pll(x, b));
  }
  for (ll i = 1; i <= N; i++) dis[i] = INF;
  djikstra(1);
  cout << dis[N] << " " << num[N] << " " << minFlights[N] << " " << maxFlights[N];
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
Input:
4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3

Output:
5 2 1 2
*/