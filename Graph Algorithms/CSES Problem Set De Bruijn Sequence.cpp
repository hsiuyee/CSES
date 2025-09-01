// refer to: https://usaco.guide/adv/eulerian-tours?lang=cpp
// #include <bits/stdc++.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <tuple>
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
#define rep(i, n) for (ll i = 1; i <= n; i++)
#define lowbit(x) x&(-x)

const ll MAXN = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1000000007;

ll N, M;
vector<ll> ans;

void find_DBS() {
    vector<vector<int> > G(1 << (N-1));
    for (ll i = 0; i < (1 << (N-1)); i++) {
        ll nxt = (i << 1) % (1 << (N-1));
        G[i].push_back(nxt);
        G[i].push_back(nxt | 1);
    }
    stack<ll> edges;
    edges.push(0);
    while (edges.size()) {
        ll node = edges.top();
        if (G[node].size()) { // add Eulerian Tours
            ll nxt = G[node].back();
            edges.push(nxt);
            // cout << "case 1: " << node << " " << nxt << "\n";
            G[node].pop_back();
        }
        else { // add edges mark
            ans.push_back(node & 1);
            edges.pop();
        }
    }
}


void solve() {
  cin >> N;
  if (N == 1) {
    cout << "01\n";
    return;
  }
  find_DBS();
  for (ll i = 0; i < N-2; i++) ans.push_back(0);
  for (auto it : ans) cout << it;
  cout << "\n";
}

signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}

/*
Input:
2

Output:
00110
*/