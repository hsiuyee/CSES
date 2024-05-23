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

const ll MAXN = 1e5 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll A, B;

void solve(){
    string s;
    cin >> s;
    map<char, ll> mp;
    vector<char> ans;
    for(auto it : s){
        mp[it]++;
    }
    ll oddNum = 0;
    char oddChar;
    for(auto it : s){
        if(mp[it] % 2 != 0){
            oddNum++;
            oddChar = it;
            for(int i = 0; i < mp[it]/2; i++){
                ans.push_back(it);
            }
            mp[it] = 0;
        }
        else{
            for(int i = 0; i < mp[it]/2; i++){
                ans.push_back(it);
            }
            mp[it] = 0;
        }
    }
    if(s.size() % 2 == 0){
        if(oddNum){
            cout << "NO SOLUTION\n";
            return;
        }
        else{
            for(auto it : ans) cout << it;
            reverse(all(ans));
            for(auto it : ans) cout << it;
        }
    }
    else{
        if(oddNum > 1){
            cout << "NO SOLUTION\n";
            return;
        }
        else{
            for(auto it : ans) cout << it;
            cout << oddChar;
            reverse(all(ans));
            for(auto it : ans) cout << it;
        }
    }
    
}

signed main() {
  fastio ll T = 1;
//   cin >> T;
  for (ll i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
