#include <algorithm>
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

const ll MAXN = 1e6 + 5;
const ll INF = 1e18;

ll K;

ll fastpow(ll x, ll k){
  if (k == 0) return 1;
  else if (k == 1) return x;
  else if (k % 2 == 0) return fastpow(x * x, k/2);
  else return fastpow(x * x, k/2) * x;
}

void solve(){
  cin >> K;
  ll n = 1, ans;
  // # of 1 digit : 9
  // # of 2 digit : 90 * 2
  // # of 3 digit : 900 * 3
  // # of n digit : 9 * n * 10^(n-1)
  while(K > 9 * n * fastpow(10, n - 1)){
      K -= 9 * n * fastpow(10, n - 1);
      n++;
  }

  // start from pow(10, n - 1)
  // move (K - 1) / n numbers;
  ans = fastpow(10, n - 1) + (K - 1) / n;
  
  // the position of numbers
  // 0-base
  K = (K - 1) % n; 

  // find such number
  ans = (ans / fastpow(10, n - K - 1)) % 10;
  cout << ans << "\n";
}
signed main() {
  fastio ll T = 1;
  cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}