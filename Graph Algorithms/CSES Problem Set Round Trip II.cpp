// Note that we don't need to maximum k
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
 
ll N, M, vis[MAXN], pre[MAXN];
vector<ll> G[MAXN];

void dfs(ll x){
    vis[x] = 1;
    for(auto it : G[x]){
        if(vis[it] == 1){
            vector<ll> ans;
            ans.push_back(x);
            while(ans.back() != it){
                ans.push_back(pre[ans.back()]);
            }
            ans.push_back(x);
            reverse(all(ans));
            cout << ans.size() << "\n";
            for(auto it2 : ans){
                cout << it2 << " ";
            }
            exit(0);
        }
        if(!vis[it]){
            pre[it] = x;
            dfs(it);
        }
    }
    vis[x] = 2;
}

void solve(){
    cin >> N >> M;
    ll x, y;
    for (ll i = 1; i <= M; i++){
        cin >> x >> y;
        G[x].push_back(y);
    }
    for(ll i = 1; i <= N; i++){
        if(!vis[i]){
            pre[i] = i;
            dfs(i);
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