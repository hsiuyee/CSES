// refer to: https://usaco.guide/gold/dp-trees?lang=cpp
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
 
const ll MAXN = 2e5 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, M, dp[MAXN][2];
vector<ll> G[MAXN];

void dfs(ll root, ll pre){
    for(auto it : G[root]){
        if(it != pre){
            dfs(it, root);
            dp[root][0] += max(dp[it][1], dp[it][0]);
        }
    }
    for(auto it : G[root]){
        if(it != pre){
            dp[root][1] = max(dp[root][1], dp[it][0] + 1 + dp[root][0] - max(dp[it][0], dp[it][1]));
        }
    }
}

void solve(){
    cin >> N;
    for(ll i = 1; i <= N-1; i++){
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}