// #include<bits/stdc++.h>
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
const ll MOD = 1234567891;
const ll P = 989898989;
 
struct BIT {
    ll arr[MAXN];
    ll n;
    void init(ll _n) {
        n = _n;
        fill(arr, arr+n+1, 0);
    }
    void modify(ll ind, ll v) {
        while (ind <= n) {
            arr[ind] += v;
            ind += lowbit(ind);
        }
    }
    ll query(ll ind) {
        ll ans = 0;
        while(ind) {
            ans += arr[ind];
            ind -= (lowbit(ind));
        }
        return ans;
    }
};

struct op {
    char q;
    ll a, b;
};


ll N, Q, a[MAXN], x, y;
vector<op> operations;

void preprocess() {
    cin >> N >> Q;
    operations.resize(N);
    for (ll i = 0; i < N; i++) cin >> a[i];
    for (ll i = 0; i < Q; i++) cin >> operations[i].q >> operations[i].a >> operations[i].b;
    vector<ll> mapping;
    for (ll i = 0; i < N; i++) {
        mapping.push_back(a[i]);
    }
    for (ll i = 0; i < Q; i++) {
        mapping.push_back(operations[i].a);
        mapping.push_back(operations[i].b);
    }
    sort(all(mapping));
    mapping.erase(unique(all(mapping)), mapping.end());
    for (ll i = 0; i < N; i++) {
        a[i] = lower_bound(all(mapping), a[i]) - mapping.begin() + 1;
    }
    for (ll i = 0; i < Q; i++) {
        if (operations[i].q == '?') operations[i].a = lower_bound(all(mapping), operations[i].a) - mapping.begin() + 1;
        else operations[i].a -= 1;
        operations[i].b = lower_bound(all(mapping), operations[i].b) - mapping.begin() + 1;
    }
}

void solve() {
    preprocess();
    BIT bit;
    bit.init(1000000);
    for (ll i = 0; i < N; i++) bit.modify(a[i], 1);
    for (ll i = 0; i < Q; i++) {
        // cout << "operations[i].a is " << operations[i].a << "\n";
        if (operations[i].q == '!') {
            ll val = a[operations[i].a];
            bit.modify(val, -1);
            bit.modify(operations[i].b, 1);
            a[operations[i].a] = operations[i].b;
        }
        else {
            ll ans = bit.query(operations[i].b) - bit.query(operations[i].a-1);
            cout << ans << "\n";
        }
    }
}
signed main() {
  fastio ll T = 1;
  // cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
 
/*
Input:
5
2 6 1 4 2
3 1 3 1 1

Output:
1 2 2 6 4
*/