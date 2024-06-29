#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
#include <cstring>
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
#define sz(a) (int) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, n) for (int i = 1; i <= n; i++)
#define lowbit(x) x &(-x)
 
const int MAXN = 20;
const int INF = 5e18;
const ll MOD = 1e9 + 7;
ll N, X, a[MAXN];
pll dp[(1 << MAXN)];
// dp[state]: when state = state, the best way
// but these is false, because, this way is equivalent to pick small people as first

pll f(ll state){
    if(dp[state].F != INF){
        return dp[state];
    }
    pll ans = mkp(INF, 0ll);
    for(ll i = 0; i < N; i++){
        ll newState = state ^ (1 << i);
        pll tempAns;
        if(state & (1 << i)){
            tempAns = f(newState);
            if(tempAns.S + a[i] > X){
                tempAns.F += 1;
                tempAns.S = a[i];
            }
            else{
                tempAns.S = (tempAns.S + a[i]);
            }
            ans = min(ans, tempAns);
        }
    }
    return dp[state] = ans;
}

void solve(){
    cin >> N >> X;
    for (ll i = 0; i < (1 << N); i++){
        dp[i] = mkp(INF, 0);
    }
    dp[0] = mkp(0, 0);
    for(ll i = 0; i < N; i++){
        cin >> a[i];
        dp[(1 << i)] = mkp(1, a[i]);
    }
    cout << f((1 << N) - 1).F << "\n";
}
 
signed main() {
  fastio int T = 1;
//   cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
