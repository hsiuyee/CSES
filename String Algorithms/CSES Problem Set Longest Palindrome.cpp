// refer to: https://oi-wiki.org/string/manacher/ https://www.geeksforgeeks.org/cses-solution-longest-palindrome/
// refer to: https://medium.com/hoskiss-stand/manacher-299cf75db97e
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
ll oddLength[1000005], evenLength[1000005];

void solve(){
    string s;
    cin >> s;
    ll N = s.size();
    for(ll i = 0, left = 0, right = -1; i < N; i++){
        ll length = (i > right) ? 1 : min(oddLength[left + right - i], right - i + 1);

        while(0 <= i - length && i + length < N && s[i - length] == s[i + length]){
            length++;
        }
        oddLength[i] = length--;
        if(i + length > right){
            left = i - length;
            right = i + length;
        }
    }
    for(ll i = 0, left = 0, right = -1; i < N; i++){
        ll length = (i > right) ? 0 : min(evenLength[left + right - i + 1], right - i + 1);
        while (0 <= i - length - 1 && i + length < N
               && s[i - length - 1] == s[i + length]) {
            length++;
        }
        evenLength[i] = length--;
        if(i + length > right){
            left = i - length - 1;
            right = i + length;
        }
    }
    ll maxLength = 0, center = -1; 
    for (int i = 0; i < N; i++) {
        if (oddLength[i] * 2 - 1 > maxLength) {
            maxLength = oddLength[i] * 2 - 1;
            center = i;
        }
        if (evenLength[i] * 2 > maxLength) {
            maxLength = evenLength[i] * 2;
            center = i;
        }
    }

    if (maxLength % 2 == 1) cout << s.substr(center - maxLength / 2, maxLength);
    else cout << s.substr(center - maxLength / 2, maxLength);
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}