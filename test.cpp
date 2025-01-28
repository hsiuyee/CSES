#include <iostream>
#include <random>
#include <ctime>
#include <queue>
#include <set>
#include <cmath> 
#include <map>
#include <algorithm>
#include <ctime> 

using namespace std;
#define ll long long
#define mkp make_pair
#define sz(a) a.size()
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pll pair<ll,ll>
#define fastio ios::sync_with_stdio(false),cin.tie(0);

struct Line{
    ll a, b;
    Line(ll _a, ll _b): a(_a), b(_b) {}
    ll operator () (const ll x){
        return a * x + b;
    }
};
bool check(Line l1, Line l2, Line l3){
    return (l3.a - l2.a) * (l1.b - l2.b) >= (l3.b - l2.b) * (l1.a - l2.a);
}

const ll INF = 5e18;
const ll MAXN = 2e5 + 5;
const ll MAXM = 1e2 + 5;

ll dp[MAXN], s[MAXN], f[MAXN], N;


void solve(){
    cin >> N;
    cin >> f[0];
    f[0] *= -1;
    dp[0] = s[0] = 0;
    for(ll i = 1; i <= N; i++) cin >> s[i];
    for(ll i = 1; i <= N; i++){
        cin >> f[i];
        f[i] *= -1;
    }
    deque<Line> dq;
    dq.push_back(Line(f[0], dp[0]));
    for(ll i = 1; i <= N; i++){
        while((ll)dq.size() >= 2 and dq[0](s[i]) <= dq[1](s[i])){
            dq.pop_front();
        }
        dp[i] = dq[0](s[i]);
        Line l = Line(f[i], dp[i]);
        while((ll)dq.size() >= 2 and check(dq[(ll)dq.size() - 2], dq[(ll)dq.size() - 1], l)){
            dq.pop_back();
        }
        dq.push_back(l);
    }
    cout << (-dp[N]) << "\n";
}

signed main(){
	fastio
	ll T = 1;
	// cin >> T;
	for(ll i = 0; i < T; i++){
		solve();
	}
	return 0;
}