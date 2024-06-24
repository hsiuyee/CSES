// refer to: https://usaco.guide/problems/cses-1196-flight-routes/solution, https://yuihuang.com/cses-1196/
// maintain best k solutions for each points
// we note that these k solution will be optimal due to dij. algorithm
// also, because the greedy selection, the correctness garantees.
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
 
ll N, M, K;
vector<pll> G[MAXN];
vector<ll> ans[MAXN];

void dij(ll root){
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push(mkp(0, root));
    while(pq.size()){
        ll d = pq.top().F;
        ll nd = pq.top().S;
        pq.pop();
        // cout << d << " " << nd << "\n";
        if(sz(ans[nd]) == K) continue;
        ans[nd].push_back(d);
        for(auto it : G[nd]){
            pq.push(mkp(d + it.F, it.S));
        } 
    }
    for(auto it : ans[N]){
        cout << it << " ";
    }
}
void solve(){
    cin >> N >> M >> K;
    ll x, y, z;
    for (ll i = 1; i <= M; i++){
        cin >> x >> y >> z;
        G[x].push_back(mkp(z, y));
    }
    dij(1);
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}