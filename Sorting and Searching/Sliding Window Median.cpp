// refer to: https://usaco.guide/problems/cses-1076-sliding-median/solution

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
 
ll N, M;
ll arr[MAXN];
multiset<ll> low, high;

void ins(ll val) {         
	ll lowMax = *low.rbegin();
    if(lowMax < val){
        high.insert(val);
        if(high.size() > M / 2){
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }
    else{
        low.insert(val);
        if(low.size() > (M+1) / 2){
            high.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void er(long val) {
    if (high.find(val) != high.end()) high.erase(high.find(val));
    else low.erase(low.find(val));
    if (low.empty()) {
        low.insert(*high.begin());
        high.erase(high.begin());
    }
}

void solve(){
    cin >> N >> M;
	for (ll i = 0; i < N; i++) cin >> arr[i];
	low.insert(arr[0]);
	for (ll i = 1; i < M; i++) ins(arr[i]);
	cout << *low.rbegin() << " ";
	for (ll i = M; i < N; i++) {
		if (M == 1) {
			cout << arr[i] << " ";
		} else {
			er(arr[i - M]);
			ins(arr[i]);
            cout << *low.rbegin() << " ";
		}
	}
	cout << endl;
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}