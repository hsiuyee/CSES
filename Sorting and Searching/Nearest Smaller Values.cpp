// refer to: https://hackmd.io/@sa072686/cp/%2F%40sa072686%2FHJrpuTZjQ
// Obs: if there are k element LHS, then if there are k+1 element LHS (add one element RHS)
// the ans is larger or equal, and I don't need to care the element 
//      which larger or equadl than the additional element
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
 
ll N, a[MAXN];
multiset<pll> st;
 
void solve(){
    cin >> N;
    vector<pll> stk;
    for(ll i = 1; i <= N; i++){
        cin >> a[i];
        while(stk.size() and stk.back().F >= a[i]){
            stk.pop_back();
        }
        if(!stk.size()) cout << 0 << " ";
        else cout << stk.back().S << " ";
        stk.push_back(mkp(a[i], i));
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