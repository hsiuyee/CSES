// refer to: Centroid Decomposition
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
 
ll N;
ll subtree_size[MAXN];
vector<ll> G[MAXN];

ll get_subtree_size(ll root, ll pre){
    subtree_size[root] = 1;
    for(auto it : G[root]){
        if(it == pre) continue;
        else{
            subtree_size[root] += get_subtree_size(it, root);
        }
    }
    return subtree_size[root];
}

ll get_centroid(ll root, ll pre){
    for(auto it : G[root]){
        if(it == pre) continue;
        else{
            if(subtree_size[it] * 2 > N) return get_centroid(it, root);
        }
    }
    return root;
}

void solve(){
    cin >> N;
    for(ll i = 0; i < N-1; i++){
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    get_subtree_size(1, 0);
    cout << get_centroid(1, 0) << "\n";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}