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

ll A, B, w[MAXN];

void solve(){
    ll N;
    cin >> N;
    ll ans = 1e18;
    for(ll i = 0; i < N; i++) cin >> w[i];
    for(ll i = 0; i < (1 << N); i++){
        ll sum1 = 0, sum2 = 0;
        for(ll j = 0; j < N; j++){
            if((1 & (i >> j)) == 0){
                sum1 += w[j];
            }
            else{
                sum2 += w[j];
            }
        }
        // cout << sum1 << " " << sum2 << "\n";
        ans = min(ans, abs(sum1 - sum2));
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
