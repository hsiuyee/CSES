// Note that each applicants assigned at most one apartments
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

ll N, M, K, a[MAXN], b[MAXN];

void solve(){
    cin >> N >> M >> K;
    for(ll i = 0; i < N; i++) cin >> a[i];
    for(ll i = 0; i < M; i++) cin >> b[i];
    sort(a, a+N);
    sort(b, b+M);
    ll lptr = 0, rptr = 0, ans = 0;
    while(lptr < N and rptr < M){
        if(a[lptr] - K <= b[rptr] and b[rptr] <= a[lptr] + K){
            lptr++;
            rptr++;
            ans++;
        }
        else if(a[lptr] - K > b[rptr]){
            rptr++;
        }
        else{
            lptr++;
        }
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
