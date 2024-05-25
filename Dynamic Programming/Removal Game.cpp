// refer to: Removal https://hackmd.io/@tmting39/H1yvegOYn#Removal-Game
// we see the difference of interval

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
 
const ll MAXN = 5005;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, dp[MAXN][MAXN], pre[MAXN];
 
 
void solve(){
    cin >> N;
    for (ll i = 1; i <= N; i++)
        for (ll j = 1; j <= N; j++)
            dp[i][j] = -INF;
    for (ll i = 1; i <= N; i++){
        cin >> pre[i];
        dp[i][i] = pre[i];
        pre[i] += pre[i-1];
    }

    for(ll len = 1; len < N; len++){
        for(int i = 1; i <= N; i++){
            ll j = i + len;
            dp[i][j] = max(dp[i][j], pre[j] - pre[i - 1]-min(dp[i + 1][j], dp[i][j - 1]));
        }
    }
    cout << dp[1][N] << "\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}