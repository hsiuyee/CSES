// refer to: https://yuihuang.com/cses-1669/
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
 
ll N, M, p[MAXN];
vector<ll> G[MAXN];
vector<ll> ans;

void dfs(ll root,ll pre){
  for(auto it : G[root]){
    if(it == pre) continue;
    if(p[it]){
      ans.push_back(root);
      while(ans.back() != it){
        ans.push_back(p[ans.back()]); // root - ... - it - root
      }
      ans.push_back(root);
      cout << ans.size() << "\n";
      for (auto i : ans){
          cout << i << " ";
      }
      exit(0); // turn down all
    }
    p[it] = root;
    dfs(it, root);
  }
}

void solve(){
    cin >> N >> M;
    ll x, y;
    for (ll i = 1; i <= M; i++){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (ll i = 1; i <= N; i++){
        if(!p[i]){
          p[i] = i;
          dfs(i, 0);
        }
    }
    cout << "IMPOSSIBLE\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}