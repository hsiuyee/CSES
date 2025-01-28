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
    mutable ll a, b, l;
    Line(ll _a, ll _b, ll _l): a(_a), b(_b), l(_l) {}
    ll operator () (const ll x){
        return a * x + b;
    }
    bool operator <(const Line &rhs) const{
        return a < rhs.a;
    }
    bool operator <(ll rhs_l) const{
        return l < rhs_l;
    }
};

struct ConvecHullMax : std::multiset<Line, std::less<>>{
    static const ll INF = (1 << 60);
    static ll DivCeil(ll a, ll b){
        return a / b - ((a ^ b) < 0 and a % b);
    }
    bool Intersect(iterator x, iterator y){
        if(y == end()){
            x->l = INF;
            return false;
        }
        if(x->a == y->a){
            x->l = x->b > y->b ? INF : -INF;
        }
        else{
            x->l = DivCeil(y->b - x->b, x->a - y->a);
        }
        return x->l >= y->l;
    }
    void Insert(ll a, ll b){
        auto z = insert(Line(a, b, 0)), y = z++, x = y;
        while(Intersect(y, z)) z = erase(z);
        if(x != begin() and Intersect(--x, y)) Intersect(x, y = erase(y));
        while((y = x) != begin() and (--x)->l >= y-> l) Intersect(x, erase(y));
    }
    ll query(ll x) const{
        auto l = *lower_bound(x);
        return l.a * x + l.b;
    }
} convechull;

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
    convechull.Insert(f[0], dp[0]);
    for(ll i = 1; i <= N; i++){
        convechull.Insert(f[i], dp[i]);
    }
    cout << convechull.query(-dp[N]) << "\n";
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