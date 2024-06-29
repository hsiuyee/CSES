// refer to: https://hackmd.io/@WinLiu/B1or3Ht5T?utm_source=preview-mode&utm_medium=rec
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
ll A, B;
ll dp[20][10][2][2];
// now position / previous number / achieve upper bound ? / leading zero ?

ll cal(string s, ll pos, ll pre, bool limit, bool lead){
    // we have already calculated answer
    if(dp[pos][pre][limit][lead] != -1) return dp[pos][pre][limit][lead];
    // only one possible case
    if(pos == s.size()){
        return dp[pos][pre][limit][lead] = 1;
    }
    ll ans = 0;
    for(ll now = 0; now <= (limit ? s[pos]- '0' : 9); now++){
        if(now == pre){
            // cannot calculate consecutive number cases 
            // except leading zero cases
            if(pre != 0) continue;
            if(lead == false) continue;
        }
        ans += cal(s, pos + 1, now, limit & (now == (s[pos] - '0')), lead & (now == 0));
    }
    return dp[pos][pre][limit][lead] = ans;
}

void solve(){
    cin >> A >> B;
    memset(dp, -1, sizeof(dp));
    ll t1 = cal(to_string(B), 0, 0, true, true);
    memset(dp, -1, sizeof(dp));
    ll t2 = cal(to_string(A-1), 0, 0, true, true);
    cout << t1 - t2 << "\n";
}
 
signed main() {
  fastio int T = 1;
//   cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
