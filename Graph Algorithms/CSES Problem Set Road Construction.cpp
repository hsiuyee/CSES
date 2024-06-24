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
 
ll N, M, indeg[MAXN], sz[MAXN], boss[MAXN], num, maxi;
vector<ll> G[MAXN];
 
ll find(ll a){
    if(a == boss[a]) return a;
    else return boss[a] = find(boss[a]);
}
 
void join(ll a,ll b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    else if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    sz[b] = 0;
    boss[b] = a;
    num--;
    maxi = max(maxi, sz[a]);
}
void solve(){
    cin >> N >> M;
    for (ll i = 1; i <= N; i++){
        boss[i] = i;
        sz[i] = 1;
    }
    num = N;
    maxi = 1;
    ll x, y;
    for (ll i = 1; i <= M; i++){
        cin >> x >> y;
        join(x, y);
        cout << num << " " << maxi << "\n";
    }
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
