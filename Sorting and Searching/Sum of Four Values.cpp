// refer to: https://blog.csdn.net/wk131421/article/details/123493390
// refer to: https://github.com/Jonathan-Uy/CSES-Solutions/blob/main/Sorting%20and%20Searching/Sum%20of%20Four%20Values.cpp

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
 
const ll MAXN = 1e3 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, X, a[MAXN];
unordered_map<ll, vector<pll> > mp;

void solve(){
    cin >> N >> X;
    for(ll i = 1; i <= N; i++){
        cin >> a[i];
        for(ll j = 1; j < i; j++){
            ll sum = a[i] + a[j];
            if(mp.find(X - sum) != mp.end()){ // O(1)
                for(auto it : mp[X-sum]){
                    if(it.F != i and it.S != i and
                       it.F != j and it.S != j){
                        cout << it.F << " " << it.S << " " << j << " " << i << "\n";
                        return;
                    }
                }
            }
            mp[sum].push_back(mkp(j, i));
        }
    }
    cout << "IMPOSSIBLE\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}