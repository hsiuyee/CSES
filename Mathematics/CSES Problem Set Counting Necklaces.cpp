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
 
const ll MAXN = 2e6 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll t, n;

ll fastpow(ll x, ll p){
    if(p == 0) return 1;
    if(p == 1) return x;
    if(p % 2 == 0) return fastpow(x * x % MOD, p/2);
    else return (x * fastpow(x * x % MOD, p/2)) % MOD; 
}

void solve(){
    cin >> n >> t;
    ll ans;
    if(n % 2 == 1){
        ans = ((fastpow(t - 1, n) - (t - 1)) % MOD + MOD) % MOD;
    }
    else{
        ans = ((fastpow(t - 1, n) + (t - 1)) % MOD + MOD) % MOD;
    }
    cout << ans << "\n";
}
 
signed main() {
  fastio ll T = 1;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}