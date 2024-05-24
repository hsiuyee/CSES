// proof refer to: https://www.geeksforgeeks.org/cses-solutions-reading-books/

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
 
ll N, k[MAXN];

void solve(){
    cin >> N;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cin >> k[i];
        sum += k[i];
    }
    sort(k, k+N);
    sum -= k[N-1];
    if(k[N-1] >= sum){
        cout << 2 * k[N-1] << "\n";
    }
    else{
        cout << sum + k[N-1] << "\n";
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