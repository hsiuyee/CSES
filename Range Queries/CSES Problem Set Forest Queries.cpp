#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
#define ll long long
#define mkp make_pair
#define pll pair<ll, ll>
#define sz(a) a.size()
#define rep(i, n) for(ll i = 1; i <= n; i++)
#define lowbit(i) -i & i
 
const ll INF = 1e18;
const ll MAXN = 1e3 + 5;
const double eps = 1e-9;
 
ll pre[MAXN][MAXN], N, Q;
string s[MAXN];
 
void solve(){
    cin >> N >> Q;
    for(ll i = 1; i <= N; i++){
        cin >> s[i];
        s[i] = " " + s[i];
    }
    // cout << "\n\n\n";
    for(ll i = 1; i <= N; i++){
        for(ll j = 1; j <= N; j++){
            pre[i][j] = (pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]) + (s[i][j] == '*' ? 1 : 0);
            // cout << pre[i][j] << " ";
        }
        // cout << "\n";
    }
    while(Q--){
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
        // cout << "1 : " << pre[x2][y2] << "\n";
        // cout << "2: " << pre[x1 - 1][y2] << "\n";
        // cout << "3: " << pre[x2][y1 - 1] << "\n";
        // cout << "4: " << pre[x1 - 1][y1 - 1] << "\n";
        cout << ans << "\n";
    }
}
 
signed main(){
    ll T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
}