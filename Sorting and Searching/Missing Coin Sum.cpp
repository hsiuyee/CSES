// refer to: https://coding-prep.com/2023/02/03/cses-missing-coin-sum/
// Note that every coin at most use one times
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
 
ll N;
ll p[MAXN];
 
ll f(ll x){
    ll res = 0;
    for(ll i = 0; i < N; i++){
        res += abs(x-p[i]);
    }
    return res;
}

void solve(){
    ll ans = 0;
    cin >> N;
    for(ll i = 0; i < N; i++){
        cin >> p[i];
    }
    sort(p, p+N);
    for(ll i = 0; i < N; i++){
        if(p[i] - ans > 1){
            break;
        }
        ans += p[i];
    }
    cout << ans+1;
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}