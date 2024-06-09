// refer to: https://www.geeksforgeeks.org/cses-solutions-chessboard-and-queens/
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

const ll MAXN = 10;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

string s[MAXN];
ll ans, col[MAXN], row[MAXN], firstdig[MAXN * 2], seconddig[2 * MAXN];

void rec(ll r){
    if(r == 8){
        ans++;
        return;
    }
    else{
        for(ll c = 0; c < 8; c++){
            if(s[r][c] == '*' || col[c] || row[r] || firstdig[r-c+7] || seconddig[r+c]){
                continue;
            }
            else{
                col[c] = 1;
                row[r] = 1;
                firstdig[r-c+7] = 1;
                seconddig[r+c] = 1;
                rec(r+1);
                col[c] = 0;
                row[r] = 0;
                firstdig[r-c+7] = 0;
                seconddig[r+c] = 0;
            }
        }
    }
}

void solve(){
    for(ll i = 0; i < 8; i++) cin >> s[i];
    rec(0);
    cout << ans << "\n";
}

signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
