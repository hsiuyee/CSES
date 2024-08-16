// refer to: https://www.geeksforgeeks.org/cses-solutions-polygon-lattice-points/
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
 
ll N, a, b;
ll x[MAXN], y[MAXN];

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void solve(){
    ll N;
    cin >> N;
    for(ll i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    x[N] = x[0];
    y[N] = y[0];

    ll area = 0;
    for(ll i = 0; i < N; i++){
        area += x[i] * y[i + 1];
        area -= y[i] * x[i + 1];
    }
    area = abs(area);

    ll boundary = 0;
    for(ll i = 0; i < N; i++){
        if(x[i + 1] == x[i]){
            boundary += abs(y[i + 1] - y[i]);
        }
        else if(y[i + 1] == y[i]){
            boundary += abs(x[i + 1] - x[i]);
        }
        else{
            boundary += gcd(abs(x[i + 1] - x[i]), abs(y[i + 1] - y[i]));
        }
    }
    ll interior = (area + 2 - boundary) / 2;
    cout << interior << " " << boundary << "\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}