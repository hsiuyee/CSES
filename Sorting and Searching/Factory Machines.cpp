// refer to: https://www.geeksforgeeks.org/cses-solutions-nested-ranges-check/
// we can see graph [ {} ] think this correctness

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
 
ll N, k[MAXN], t;

bool isVaild(ll val){
    ll cnt = 0;
    for(int i = 0; i < N; i++) cnt += val / k[i];
    return cnt >= t;
}

void solve(){
    cin >> N >> t;
    for(int i = 0; i < N; i++) cin >> k[i];
    ll step = pow(2, 40), ans = 0;
    while(step){
        if(isVaild(step + ans)) step /= 2;
        else ans += step;
    }
    cout << ans + 1 << "\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}