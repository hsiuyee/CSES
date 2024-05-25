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
 
ll N;
ll f[MAXN];

ll fastpow(ll x, ll p){
    if(p == 0) return 1;
    if(p == 1) return x;
    if(p % 2 == 0) return fastpow(x * x % MOD, p/2);
    else return (x * fastpow(x * x % MOD, p/2)) % MOD; 
}

void solve(){
    cin >> N;
    if(N % 2 == 1){
        cout << "0\n";
        exit(0);
    }
    f[0] = 1;
    for (int i = 1; i <= N; i++) 
        f[i] = ((f[i - 1] * (4 * i - 2)) % MOD) * fastpow(i + 1, MOD-2) % MOD;
    cout << f[N/2] << "\n"; 
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}