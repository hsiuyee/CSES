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
 
const ll MAXN = 5e3 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, M, dp[MAXN][MAXN];
 
 
void solve(){
    cin >> N >> M;
    for(ll i = 0; i <= N; i++){
        for(ll j = 0; j <= M; j++){
            dp[i][j] = INF;
        }
    }
    for(ll i = 0; i <= N; i++) dp[i][i] = 0;
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= M; j++){
            if(i == j) continue;
            for(ll k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
            }
            for(ll k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
            }
        }
    }
    cout << dp[N][M] << "\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}