#include <algorithm>
// #include <bits/stdc++.h>
#include <deque>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <set>
#include <map>
#include <tuple>
#include <vector>
#include <string>
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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define lowbit(x) x &(-x)
 
const ll MAXN = 1e5 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, M, vis[MAXN], dis1[MAXN], dis2[MAXN];
vector<pll> G1[MAXN], G2[MAXN];
vector<ll> ans;

void dij(ll root, ll dis[], vector<pll> G[]){
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    for(ll i = 1; i <= N; i++){
        vis[i] = 0;
        dis[i] = INF;
    }
    dis[root] = 0;
    pq.push(mkp(dis[root], root));
    while(pq.size()){
        ll d = pq.top().F;
        ll nd = pq.top().S;
        pq.pop();
        if(dis[nd] < d) continue;
        vis[nd] = 1;
        for(auto it : G[nd]){
            if(dis[it.S] > dis[nd] + it.F){
                dis[it.S] = dis[nd] + it.F;
                pq.push(mkp(dis[it.S], it.S));
            }
        } 
    }
}
void solve(){
    cin >> N >> M;
    ll x, y, z;
    for (ll i = 1; i <= M; i++){
        cin >> x >> y >> z;
        G1[x].push_back(mkp(z, y));
        G2[y].push_back(mkp(z, x));
        // G[y].push_back(mkp(z, x));
    }
    dij(1, dis1, G1);
    dij(N, dis2, G2);
    ll cost = INF;
    for(ll i = 1; i <= N; i++){
        for(auto it : G1[i]){
            // cout << "i: " << i << " it.S: " << it.S << " w: " << it.F << "\n";
            // cout << "dis1[i]: " << dis1[i] << " dis2[it.S]: " << dis2[it.S] << "\n";
            ll tempCost = dis1[i] + dis2[it.S] + it.F / 2;
            cost = min(cost, tempCost);
        }
    }
    cout << cost;
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}