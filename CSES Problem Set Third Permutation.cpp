// refer: Erdos-Szekeres Theorem
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <numeric>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
 
const ll INF = 1e18;
const ll MOD1 = 1e9+7;
const ll MOD2 = 998244353;
 
ll fpow(ll a, ll b, ll m)
{
    if(!b) return 1;
    ll tmp = 1;
    for(ll cur = a; b; b >>= 1, cur = cur * cur % m) if(b & 1) tmp = tmp * cur % m;
    return tmp;
}
ll inv(ll a, ll m) {return fpow(a, m - 2, m);}
 
#define fastio ios::sync_with_stdio(false), cin.tie(0);
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define sz(a) (int) a.size()
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define per(i, a, b) for (ll i = (a); i >= (b); --i)
#define lowbit(x) x&(-x)
#define vi vector<int>

const ll MAXN = 1e5 + 5;
 
int N, a[MAXN], b[MAXN], ans[MAXN];
 
// ll ask(int a,int b,int c){
  
// }
 
// void ans(ll x, ll y, ll z) {
  
// }

bool isVaild(vector<ll> vec) {
    bool flag1 = (vec[0] != a[N - 2]) and (vec[0] != b[N - 2]);
    bool flag2 = (vec[1] != a[N - 1]) and (vec[1] != b[N - 1]);
    bool flag3 = (vec[2] != a[N]) and (vec[2] != b[N]);
    return flag1 && flag2 && flag3;
}

void solve() {
	cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];
    if (N == 2) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    set<int> st;
    for (int i = 1; i <= N; i++) st.insert(i);
    for (int i = 1; i <= N - 3; i++) {
        for (auto it : st) {
            if (it != a[i] and it != b[i]) {
                ans[i] = it;
                st.erase(it);
                break;
            }
        }
    }
    vector<ll> vec;
    for (auto it : st) vec.push_back(it);
    do {
        if (isVaild(vec)) {
            for (ll i = 0; i < 3; i++) ans[N - 2 + i] = vec[i];
            break;
        }
    } while (next_permutation(all(vec)));
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << "\n";
}
 
signed main() {
	fastio int T = 1;
	// cin >> T;
	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}
 
/*
0. WA1 -> multiple input
1. WA7 -> specify mod, and use mod or not
*/