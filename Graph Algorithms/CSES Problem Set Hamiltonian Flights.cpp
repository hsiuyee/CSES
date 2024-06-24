// refer to: https://yuihuang.com/cses-1690/
// note that a may equal to b
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
const int MAXF = 5e18;
const ll MOD = 1e9 + 7;
vector<ll> G[MAXN];
ll N, M;
ll dp[(1 << MAXN)][MAXN];
// need visit state, now position
// when we tranfer to now position, old position updates

ll f(ll state, ll pos){
    if(dp[state][pos] != -1) return dp[state][pos];
    ll ans = 0;
    for(auto nextPos : G[pos]){
        ll newState = state ^ (1 << pos);
        if(state & (1 << nextPos)){
            ans += f(newState, nextPos);
            ans %= MOD;
        }   
    }
    return dp[state][pos] = ans;
}

void solve(){
    cin >> N >> M;
    ll a, b;
    for (ll i = 0; i < (1 << N); i++){
        for(ll j = 0; j < N; j++){
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < M; i++){
        cin >> a >> b;
        a--;
        b--;
        if (a == b) continue;
        G[b].push_back(a);
    }
    dp[1 << 0][0] = 1;
    for(ll i = 1; i < N; i++){
        dp[(1 << i)][i] = 0;
    }
    cout << f((1 << N) - 1, N-1) << "\n";
}
 
signed main() {
  fastio int T = 1;
//   cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
