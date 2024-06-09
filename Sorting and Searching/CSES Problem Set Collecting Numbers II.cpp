// refer to: https://www.geeksforgeeks.org/cses-solutions-collecting-numbers-ii/
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
 
ll N, Q;

void solve(){
    cin >> N >> Q;
    vector<ll> a(N+1), idx(N+2);
    idx[0] = 0, idx[N+1] = N+1;
    for (ll i = 1; i <= N; i++){
        cin >> a[i];
        idx[a[i]] = i;
    }
    ll cnt = 1;
    for (ll i = 1; i <= N; i++){
        if(idx[i-1] > idx[i]) cnt++;
    }
    while(Q--){
        ll l, r;
        cin >> l >> r;
        ll x = a[l], y = a[r];
        swap(a[l], a[r]);
        if(idx[x-1] <= idx[x]   and idx[x-1] >  r) cnt++;
        if(idx[x-1] >  idx[x]   and idx[x-1] <= r) cnt--;
        if(idx[x]   <= idx[x+1] and idx[x+1] <  r) cnt++;
        if(idx[x]   >  idx[x+1] and idx[x+1] >= r) cnt--;
        idx[x] = r;

        if(idx[y-1] <= idx[y]   and idx[y-1] >  l) cnt++;
        if(idx[y-1] >  idx[y]   and idx[y-1] <= l) cnt--;
        if(idx[y]   <= idx[y+1] and idx[y+1] <  l) cnt++;
        if(idx[y]   >  idx[y+1] and idx[y+1] >= l) cnt--;
        idx[y] = l;
        cout << cnt << "\n";

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