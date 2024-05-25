// refer to: https://hackmd.io/@WinLiu/Hyom0_wN6/https%3A%2F%2Fhackmd.io%2FUaAau1ONSmCanO6QrEEqHA
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
#define int long long

const ll MAXN = 5e5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll cumulate[MAXN];

void solve(){
    // ll K;
    // cin >> K;
    // ll num_of_digit = 1, ten = 1;
    // while(K >= ten * 9 * num_of_digit){
    //   K -= ten * 9 * num_of_digit;
    //   num_of_digit++;
    //   ten *= 10;
    // }
    // ll s = (K-1) / num_of_digit;
    // ll n = ten + s;
    // for (ll i = num_of_digit; i > K - s * num_of_digit; i--) {
    //     n /= 10;
    // }
    // cout << n % 10 << "\n";
    int q, k;
    cin >> k;
    int lv = 1, ten = 1;
    while (k >= lv * 9 * ten) {
        k -= lv * 9 * ten;
        lv++;
        ten *= 10;
    }
    int s = (k-1) / lv;
    int n = ten + s;
    for (int i = lv; i > k - s*lv; i--) {
        n /= 10;
    }
    cout << n % 10 << '\n';
}

signed main() {
  fastio ll T = 1;
  cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
