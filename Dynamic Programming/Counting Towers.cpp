// refer to: https://hackmd.io/m7pu3K7QRKuDGkW4iiB-TA?view
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
 
const ll MAXN = 1e6 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll Q, dp[2][MAXN];
 
 
void solve(){
    dp[0][1] = dp[1][1] = 1;
    for(ll i = 2; i <= 1000000; i++){
        dp[0][i] = (4 * dp[0][i-1] + dp[1][i-1]) % MOD;
        dp[1][i] = (dp[0][i-1] + 2 * dp[1][i-1]) % MOD;
    }
    cin >> Q;
    while(Q--){
        ll x;
        cin >> x;
        cout << (dp[0][x] + dp[1][x]) % MOD << "\n";
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