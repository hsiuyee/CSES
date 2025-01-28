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
#define X first
#define Y second
#define pll pair<ll,ll>
#define fastio ios::sync_with_stdio(false),cin.tie(0);

const ll MAXN = 1e3 + 5;
const ll INF = 5e18;

vector<pll> p;
ll N;
pll ansX, ansY;

pll operator+(pll a,pll b){
    return pll(a.X + b.X, a.Y + b.Y);
}
pll operator-(pll a,pll b){
    return pll(a.X - b.X, a.Y - b.Y);
}
pll operator*(pll a,double b){
    return pll(a.X * b, a.Y * b);
}
pll operator/(pll a,double b){
    return pll(a.X / b, a.Y / b);
}

ll sign(ll a){
    if(abs(a) == 0) return 0;
    else{
        if(a > 0) return 1;
        else return -1;
    }
}

ll cross(pll a,pll b){
    return (a.X * b.Y - a.Y * b.X);
}

ll ori(pll a,pll b,pll c){
    return sign(cross(b-a,b-c));
}

ll dot(pll a, pll b){
    return (a.X*b.X+a.Y*b.Y);
}

ll abs2(pll a){
    return dot(a,a);
}

vector<pll> convex_hull(vector<pll> pnts){
    sort(pnts.begin(), pnts.end());
    vector<pair<ll, ll> > hull;

    for(int i = 0; i < 2; i++){
        int t = hull.size();
        for(pair<ll, ll> pnt : pnts){
            while(hull.size() - t >= 2 && cross(hull.back() - hull[hull.size() - 2], pnt - hull[hull.size() - 2]) <= 0)
                hull.pop_back();
            hull.push_back(pnt);
        }
        hull.pop_back();
        reverse(pnts.begin(), pnts.end());
    }

    return hull;
}


ll farthest_point(){
    ll ans = 0;
    vector<pll> hull = convex_hull(p);
    ll m = (ll)hull.size();
    for(ll i = 0, p = 0; i < m; i++){
        while((p + 1ll) < m and
            cross(hull[i + 1] - hull[i], hull[p] - hull[i]) <=
            cross(hull[i + 1] - hull[i], hull[p + 1] - hull[i]))
              p++;
        if(abs2(hull[i] - hull[p]) > ans){
            ansX = hull[i];
            ansY = hull[p];
            ans = max(ans, abs2(hull[i] - hull[p])); 
        }
        if(abs2(hull[i + 1] - hull[p]) > ans){
            ansX = hull[i + 1];
            ansY = hull[p];
            ans = max(ans, abs2(hull[i + 1] - hull[p]));
        }
    }
    return ans;
}

void solve(){
    cin >> N;
    p.resize(N);
    for(ll i = 0; i < N; i++) cin >> p[i].X >> p[i].Y;
    farthest_point();
    for(ll i = 0; i < N; i++){
        if(p[i] == ansX){
            cout << i << " "[ansY == mkp(-INF, -INF)];
            ansX = mkp(-INF, -INF);
        }
        if(p[i] == ansY){
            cout << i << " "[ansX == mkp(-INF, -INF)];
            ansY = mkp(-INF, -INF);
        }
    }
    cout << "\n";
    // cout << ansX.X << ansX.Y;
    // cout << ansY.X << ansY.Y;
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