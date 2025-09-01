// refer to: https://www.youtube.com/watch?v=rMK_or9QNrg&ab_channel=NeatlyStructured 0:00 ~ 10:00

// #include <bits/stdc++.h> 
#include <algorithm>
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
 
ll N, M, sum1, sum2;
ll arr[MAXN];
multiset<ll> low, high;
 
void ins(ll val) {         
	ll lowMax = *low.rbegin();
    if (lowMax < val){
        high.insert(val);
        sum2 += val;
        if(high.size() > M / 2){
            sum1 += *high.begin();
            low.insert(*high.begin());
            sum2 -= *high.begin();
            high.erase(high.begin());
            
        }
    }
    else{
        low.insert(val);
        sum1 += val;
        if(low.size() > (M + 1) / 2){
            sum2 += *low.rbegin();
            high.insert(*low.rbegin());
            sum1 -= *low.rbegin();
            low.erase(low.find(*low.rbegin()));
        }
    }
}
 
void er(long val) {
    if (high.find(val) != high.end()) {
        sum2 -= val;
        high.erase(high.find(val));
    }
    else {
        sum1 -= val;
        low.erase(low.find(val));
    }
    if (low.empty()) {
        sum1 += *high.begin();
        low.insert(*high.begin());
        sum2 -= *high.begin();
        high.erase(high.begin());
    }
}

ll cost() {
    ll ans = low.size() * (*low.rbegin()) - sum1;
    ans += sum2 - high.size() * (*low.rbegin());
    return ans;
}

void solve(){
    sum1 = sum2 = 0;
    cin >> N >> M;
	for (ll i = 0; i < N; i++) cin >> arr[i];
	low.insert(arr[0]);
    sum1 += arr[0];
	for (ll i = 1; i < M; i++) ins(arr[i]);
    cout << cost() << " ";
	for (ll i = M; i < N; i++) {
        // cout << "sum1 is " << sum1 << " " << sum2 << "\n";
		if (M == 1) {
			cout << 0 << " ";
		} else {
			er(arr[i - M]);
			ins(arr[i]);
            cout << cost() << " ";
		}
	}
	cout << endl;
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}

/*
Input:
8 3
2 4 3 5 8 1 2 1

Output:
2 2 5 7 7 1
*/