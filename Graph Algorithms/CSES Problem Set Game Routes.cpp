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
 
ll N, M, indeg[MAXN], possible[MAXN];
vector<ll> G[MAXN];
vector<ll> ans;

void topoSort(queue<ll> topo){
    while(topo.size()){
        ll now = topo.front();
        topo.pop();
        ans.push_back(now);
        for(auto it : G[now]){
            possible[it] = (possible[it] + possible[now]) % MOD;
            indeg[it]--;
            if(indeg[it] == 0){
                topo.push(it);
            }
        }
    }
    cout << (possible[N] % MOD) << "\n";
}

void solve(){
    cin >> N >> M;
    ll x, y;
    for (ll i = 1; i <= M; i++){
        cin >> x >> y;
        G[x].push_back(y);
        indeg[y]++;
    }
    possible[1] = 1;
    queue<ll> topo;
    for (ll i = 1; i <= N; i++){
        if(indeg[i] == 0){
            topo.push(i);
        }
    }
    topoSort(topo);
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}