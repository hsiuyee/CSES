// ref: https://codeforces.com/blog/entry/87585
// ref: https://codeforces.com/blog/entry/82103
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
#include <iomanip>
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


const ll MAXN = 1e7 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll n, k, frac[MAXN];

ll fastpow(ll a, ll p){
    if(p == 0) return 1;
    else if(p == 1) return a;
    else if(p % 2 == 0) return fastpow(a * a % MOD, p / 2);
    else return (a * fastpow(a * a % MOD, p / 2)) % MOD;
}

ll inv(ll a){
    return fastpow(a, MOD - 2);
}


void solve() {
    cin >> n;
    string s;
    cin >> s;
    if(n % 2 != 0){
        cout << "0\n";
        return;
    }
    n /= 2;
    ll k = 0, total_open = 0;
    for(ll i = 0; i < (ll)s.size(); i++){
        if(s[i] == '('){
            k++;
            total_open++;
        }
        else{
            k--;
            if(k < 0){
                cout << "0\n";
                return;
            }
        }
    }
    n -= total_open;
    if(k < 0 or n < 0 or 2 * n + k < n){
        cout << "0\n";
        return;
    }
    frac[0] = 1;
    for(ll i = 1; i <= 2 * n + k; i++){
        frac[i] = (frac[i - 1] * i) % MOD;
        // cout << "frac[i]: " << frac[i] << "\n";
    }
    // cout << "n: " << n << " k: " << k << "\n";
    ll ans = (frac[2 * n + k] * inv(frac[n])) % MOD;
    ans = (ans * inv(frac[n + k])) % MOD;
    ans = (ans * (k + 1)) % MOD;
    ans = (ans * inv(n + k + 1)) % MOD;
    cout << ans << "\n";
}
 
signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
