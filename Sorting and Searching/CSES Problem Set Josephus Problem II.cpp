// refer to: https://www.nirlep.dev/adventures/cses/sorting-and-searching/josephus-problem-2

#include <algorithm>
// #include <bits/stdc++.h>
// #include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
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
 
template <typename T> using indexed_set =  tree<T,\
            null_type, less<T>, rb_tree_tag,\
            tree_order_statistics_node_update>;
          
ll N, K;


void solve(){
    int N, K;
    cin >> N >> K;

    indexed_set<int> survivals;
    for (int i = 1; i <= N; i++) survivals.insert(i);

    int index = K + 1;
    while (survivals.size() > 1) {
        index %= survivals.size();
        if (index == 0) index = survivals.size();

        auto it = survivals.find_by_order(index - 1);
        cout << *it << " ";
        survivals.erase(it);

        index += K;
    }

    cout << *survivals.begin() << endl;
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}