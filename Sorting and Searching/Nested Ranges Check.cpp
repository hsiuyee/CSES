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
 
ll N, contain[MAXN], contained[MAXN];

void solve(){
    cin >> N;
    vector<pair<pll, ll> > vec(N);
    for(ll i = 0; i < N; i++){
        cin >> vec[i].F.F >> vec[i].F.S;
        vec[i].F.S *= -1;
        vec[i].S = i;
    }
    sort(all(vec));
    ll minEnd = -INF;
    for(ll i = N-1; i >= 0; i--){
        if(minEnd >= vec[i].F.S){
            contain[vec[i].S] = 1;
        }
        minEnd = max(minEnd, vec[i].F.S);
    }
    for(ll i = 0; i < N; i++) cout << contain[i] << " ";
    cout << "\n";
    ll maxEnd = 1;
    for(ll i = 0; i < N; i++){
        if(maxEnd <= vec[i].F.S){
            contained[vec[i].S] = 1;
        }
        maxEnd = min(maxEnd, vec[i].F.S);
    }
    for(ll i = 0; i < N; i++) cout << contained[i] << " ";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}