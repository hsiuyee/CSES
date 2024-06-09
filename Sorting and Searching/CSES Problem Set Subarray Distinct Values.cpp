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
 
ll N, K, x[MAXN];

void solve(){
    cin >> N >> K;
    ll ans = 0;
    queue<ll> qu;
    map<ll, ll> mp;
    ll diff = 0;
    for(int i = 0; i < N; i++){
        cin >> x[i];
        mp[x[i]]++;
        qu.push(x[i]);
        if(mp[x[i]] == 1) diff++;
        while(qu.size() and diff > K){
          ll now = qu.front();
          qu.pop();
          mp[now]--;
          if(mp[now] == 0) diff--;
        }
        ans += qu.size();
    }
    cout << ans << "\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}