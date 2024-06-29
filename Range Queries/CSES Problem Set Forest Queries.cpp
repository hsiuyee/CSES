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
 
ll bit[MAXN * MAXN], N, Q;
string s[MAXN];

void upd(ll k, ll u){
    for(ll i = k; i <= N; i += lowbit(i)){
        bit[i] += u;
    }
}
 
ll qry(ll k){
    ll res = 0;
    for(ll i = k; i > 0; i -= lowbit(i)){
        res += bit[i];
    }
    return res;
}
 
void solve(){
    cin >> N >> Q;
    map<pll, ll> mp;
    ll count = 1;
    rep(i, N){
        cin >> s[i];
        rep(j, N){
            mp[mkp(i, j)] = count;
            if(s[i][j-1] == '*'){
                upd(count, 1);
            }
            count++;
        }
    }
    while(Q--){
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = qry(mp[mkp(x2, y2)]) - qry(mp[mkp(x1, y2)]) - qry(mp[mkp(x2, y1)]);
        if(mp.find(mkp(x1-1, y2-1)) != mp.end()){
            ans -= qry(mp[mkp(x1-1, y2-1)]);
        }
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