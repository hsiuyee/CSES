#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
 
#define int long long
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
 
const int MAXN = 3000 + 5;
const int MAXF = 5e18;
// const ll MOD = 1e9 + 7;
vector<vector<int> > ans;
 
struct Dinic {
  struct edge {
    int to, cap, flow, rev;
  };
  // static constexpr int MAXN = 1050, MAXF = 1e9;
  vector<edge> v[MAXN];
  int top[MAXN], deep[MAXN], side[MAXN], s, t;
  void make_edge(int s, int t, int cap) {
    edge e;
    e.to = t;
    e.cap = cap;
    e.flow =  0;
    e.rev = (int)v[t].size();
    v[s].emplace_back(e);
    e.to = s;
    e.cap = 0;
    e.flow = 0;
    e.rev = (int)v[s].size() - 1;
    v[t].push_back(e);
  }
  int dfs(int a, int flow) {
    if (a == t || !flow) return flow;
    for (int &i = top[a]; i < v[a].size(); i++) {
      edge &e = v[a][i];
      if (deep[a] + 1 == deep[e.to] && e.cap - e.flow) {
        int x = dfs(e.to, min(e.cap - e.flow, flow));
        if (x) {
          e.flow += x, v[e.to][e.rev].flow -= x;
          return x;
        }
      }
    }
    deep[a] = -1;
    return 0;
  }
  bool bfs() {
    queue<int> q;
    fill_n(deep, MAXN, 0);
    q.push(s), deep[s] = 1;
    int tmp;
    while (!q.empty()) {
      tmp = q.front(), q.pop();
      for (edge e : v[tmp])
        if (!deep[e.to] && e.cap != e.flow)
          deep[e.to] = deep[tmp] + 1, q.push(e.to);
    }
    return deep[t];
  }
  int max_flow(int _s, int _t) {
    s = _s, t = _t;
    int flow = 0, tflow;
    while (bfs()) {
      fill_n(top, MAXN, 0);
      while ((tflow = dfs(s, MAXF))) flow += tflow;
    }
    return flow;
  }
  void reset() {
    fill_n(side, MAXN, 0);
    for (auto &i : v) i.clear();
  }
};
 
 
void solve(){
    int N, M;
    cin >> N >> M;
    Dinic flow;
    int a, b, c, s, t;
    s = 1;
    t = 2 * N - 2;
    int ans = 0;
    rep(i, M){
        cin >> a >> b >> c;
        // cout << "a: " << a << " b: " << b << " c: " << c << "\n";
        if(a == 1 and b == N) ans += max(c, 0ll);
        else if(a == N and b == 1) continue;
        else if(a == 1){
            flow.make_edge(s, b, c);
        }
        else if(b == N){
            flow.make_edge(a + (N-2), t, c);
        }
        else{
            flow.make_edge(a, b + (N-2), c);
        }
    }
    for (int i = 2; i < N; i++){
        flow.make_edge(i, i + (N-2), MAXF);
        flow.make_edge(i + (N-2), i, MAXF);
    }
    cout << (ans + flow.max_flow(s, t)) << "\n";
}
 
signed main() {
  fastio int T = 1;
  // cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
