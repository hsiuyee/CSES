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

ll A, B;

void solve(){
  cin >> A >> B;
  ll flag = 0;
  if(A < B) swap(A, B);
  if(2 * B - A < 0) flag = 1;
  if((2 * A - B) % 3 != 0) flag = 1;
  if((2 * B - A) % 3 != 0) flag = 1;    
  if(flag) cout << "NO\n";
  else cout << "YES\n";
}

signed main() {
  fastio ll T = 1;
  cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
