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
#include <iomanip>
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


const ll MAXN = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll a[MAXN], N, K;

void solve() {
    cin >> N >> K;
    ll ans = 0;
    for(ll i = 0; i < K; i++) cin >> a[i];
    for(ll i = 0; i < (1 << K); i++){
        ll prod = 1;
        ll odd = 0;
        for(ll j = 0; j < K; j++){
            if((1 << j) & i){
                if(prod > N / a[j]){
                    prod = N + 1;
                    break;
                }
                else{
                    prod *= a[j];
                    odd ^= 1;
                }
            }
        }
        if(odd) ans -= (N / prod);
        else ans += (N / prod);
        // cout << odd << " " << prod << " " << N / prod << "\n";
    }
    cout << N - ans << "\n";
}
 
signed main() {
  // fastio 
  ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
