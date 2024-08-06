#include <algorithm>
// #include <bits/stdc++.h>
#include <deque>
#include <stack>
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
 
const ll MAXN = 2505;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, M, dis[MAXN], par[MAXN], cnt[MAXN];
ll end_point;
vector<pll> G[MAXN];
bool in_queue[MAXN], vis[MAXN];
bool ansVis[MAXN];

bool spfa(ll root){
    dis[root] = 0;
    par[root] = -1;
    queue<ll> q;
    q.push(root);
    in_queue[root] = true;
    while(q.size()){
        ll now = q.front();
        vis[now] = true;
        in_queue[now] = false;
        q.pop();
        for(auto it : G[now]){
            ll v = it.F;
            ll w = it.S;
            if(dis[v] > dis[now] + w){
                par[v] = now;
                cnt[v]++;
                if(cnt[v] > N){
                    end_point = v;
                    return false;
                }
                dis[v] = dis[now] + w;
                if(!in_queue[v]){
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
    return true;
}

void solve(){
    cin >> N >> M;
    ll x, y, z;
    for(ll i = 1; i <= N; i++) dis[i] = INF;
    for (ll i = 1; i <= M; i++){
        cin >> x >> y >> z;
        G[x].push_back(mkp(y, z));
    }
    for(ll i = 1; i <= N; i++){
        if(!spfa(i)){
            cout << "YES\n";
            // stack<ll> vec;
            vector<ll> vec;
            while(!ansVis[end_point]){
                ansVis[end_point] = true;
                // vec.push(end_point);
                vec.push_back(end_point);
                end_point = par[end_point];
            }
            cout << end_point << " ";
            reverse(all(vec));
            for(auto it : vec){
                if(it == end_point) break;
                cout << it << " ";
            }
            cout << end_point << "\n";
            // note the total path is not always a cycle.
            return;
        }
    }
    cout << "NO\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}