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
 
ll N, M, indeg[MAXN], pre[MAXN], dis[MAXN];
vector<ll> G[MAXN];
vector<ll> ans;

void solve(){
    cin >> N >> M;
    ll x, y;
    for(ll i = 1; i <= N; i++){
        pre[i] = -1;
        dis[i] = -1e9;
    }
    for (ll i = 1; i <= M; i++){
        cin >> x >> y;
        G[x].push_back(y);
        indeg[y]++;
    }
    dis[1] = 0;
    pre[1] = 1;
    queue<ll> qu;
    for(ll i = 1; i <= N; i++){
        if(indeg[i] == 0){
            qu.push(i);
        }
    }
    while(qu.size()){
        ll now = qu.front();
        qu.pop();
        for(auto it : G[now]){
            if(dis[it] < dis[now] + 1){
                dis[it] = dis[now] + 1;
                pre[it] = now;
            }
            indeg[it]--;
            if(indeg[it] == 0){
                qu.push(it);
            }
        }
    }
    vector<ll> ans;
    if(dis[N] < 0){
        cout << "IMPOSSIBLE";
        return;
    }
    else{
        ll now = N;
        while(true){
            ans.push_back(now);
            if(now == pre[now]) break;
            else now = pre[now];
        }
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    for(auto it : ans) cout << it << " ";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}