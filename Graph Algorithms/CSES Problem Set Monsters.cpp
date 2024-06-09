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
 
const ll MAXN = 1e3 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, M;
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
char sign[5] = {'R', 'L', 'U', 'D', '-'};
string mp[MAXN];
char state[MAXN];

vector<ll> ans;

vector<ll> bfs(ll x, ll y){
    queue<pll> qu;
    qu.push(mkp(x, y));
    while(qu.size()){

    }
}

void solve(){
    cin >> N >> M;
    for(ll i = 1; i <= N; i++){
        string tmp;
        cin >> tmp;
        mp[i] = '-' + tmp;
    }
    for(ll i = 1; i <= N; i++)
        cout << mp[i] << "\n";

    for(ll i = 1; i <= M; i++){
        bfs(0, i);
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