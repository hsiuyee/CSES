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
 
const ll MAXN = 1e3 + 5;
// const ll MAXM = 1e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
 
ll N, M;
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
char sign[5] = {'R', 'L', 'U', 'D', '-'};
bool vis[MAXN][MAXN];
string graph[MAXN];
map<char, ll> signToIndex;
pair<ll, char> transition[MAXN][MAXN];
// dis, transfer

bool isVaild(ll x, ll y){
  return 0 <= x and x < N and 0 <= y and y < M and !vis[x][y] and graph[x][y] != '#';
}

vector<ll> bfs(ll x, ll y){
    queue<pll> qu;
    qu.push(mkp(x, y));
    vis[x][y] = true;
    transition[x][y] = mkp(0, '-');
    while(qu.size()){
      ll curx = qu.front().F;
      ll cury = qu.front().S;
      qu.pop();
      for(ll i = 0; i < 4; i++){
        ll nx = curx + dx[i];
        ll ny = cury + dy[i];
        if(isVaild(nx, ny)){
          vis[nx][ny] = true;
          transition[nx][ny] = mkp(transition[curx][cury].F + 1, sign[i]);
        }
      }
    }
}

void solve(){
  ll Mx, My, Sx, Sy;
  for(ll i = 0; i < 4; i++){
    signToIndex[sign[i]] = i;
  }
  cin >> N >> M;
  for(ll i = 0; i < N; i++){
    cin >> graph[i];
  }
  for(ll i = 0; i < N; i++){
    for(ll j = 0; j < M; j++){
      if(graph[i][j] == 'M'){
        Mx = i;
        My = j;
      }
      else if(graph[i][j] == 'A'){
        Sx = i;
        Sy = j;
      }
    }
  }
  bfs(Mx, My);
  ll minDis = INF;
  for(ll i = 0; i < N; i++){
    for(ll j = 0; j < M; j++){
      if(graph[i][j] == 'M'){
        Mx = i;
        My = j;
      }
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