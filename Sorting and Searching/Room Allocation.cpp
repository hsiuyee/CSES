// refer to: https://www.geeksforgeeks.org/cses-solutions-nested-ranges-check/
// we can see graph [ {} ] think this correctness

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
 
ll N, room[MAXN];


void solve(){
    cin >> N;
    vector<pair<pll, ll> > vec(N);
    for(ll i = 0; i < N; i++){
        cin >> vec[i].F.F >> vec[i].F.S;
        vec[i].S = i;
    }
    sort(all(vec));
    ll ans = 0;
    set<pair<pll, ll> > st;
    for(ll i = N-1; i >= 0; i--){
        // cout << i << " vec " << vec[i].F.F << " " << vec[i].F.S << " " << "\n";
        if(st.empty()){
            st.insert(vec[i]);
            ans++;
            room[vec[i].S] = ans;
        }
        else{
            auto it = st.upper_bound(mkp(mkp(vec[i].F.S, INF), 0));
            pair<pll, ll> tmp = *it;
            // cout << i << " " << tmp.F.F << " " << tmp.F.S << " " << "\n";
            if(it == st.end()){
                ans++;
                room[vec[i].S] = ans;
                st.insert(vec[i]);
            }
            else{
                room[vec[i].S] = room[tmp.S];
                st.erase(it);
                st.insert(vec[i]);
            }
        }
    }
    cout << ans << "\n";
    for(ll i = 0; i < N; i++) cout << room[i] << " ";
}
 
signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}