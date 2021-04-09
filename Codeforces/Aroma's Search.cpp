#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dist(pair<ll, ll> a, pair<ll, ll> b){
	return abs(a.se - b.se) + abs(a.fi - b.fi);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll x, y, ax, ay, bx, by;
	cin >> x >> y >> ax >> ay >> bx >> by;
	ll xs, ys, t;
	cin >> xs >> ys >> t;
	vector<pair<ll, ll>> p;
	p.pb(mp(x, y));
	pair<ll, ll> lst = p[0], st = mp(xs, ys);
	ll mx = 4e18;
	while(true){
		if((mx / ax) < lst.fi) break;
		if((mx / ay) < lst.se) break;
		pair<ll, ll> cur = mp(ax * lst.fi + bx, ay * lst.se + by);
		if(cur.fi > 1e17 || cur.se > 1e17) break;
		if(cur == lst) break;
		lst = cur;
		p.pb(cur);
	}
	int n = p.size(), ans = 0;
	rep(i, n){
		ll d = 0LL;
		int cur = 0;
		pair<ll, ll> pr = st;
		repn(j, i, n){
			d += dist(pr, p[j]);
			pr = p[j];
			if(d > t) break;
			cur++;
		}
		ans = max(ans, cur);
	}
	reverse(all(p));
	rep(i, n){
		ll d = 0LL;
		int cur = 0;
		pair<ll, ll> pr = st;
		repn(j, i, n){
			d += dist(pr, p[j]);
			pr = p[j];
			if(d > t) break;
			cur++;
		}
		ans = max(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
