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

ll dist(pi a, pi b){
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	pi mn = p[0], mx = p[0];
	sort(all(p));
	ll ans = 0LL;
	repn(i, 1, n){
		ans = max(ans, dist(p[i], mn));
		ans = max(ans, dist(p[i], mx));
		if(p[i].se > mx.se && (p[i].fi - mx.fi) < (p[i].se - mx.se)) mx = p[i];
		if(p[i].se < mn.se && (p[i].fi - mn.fi) < (mn.se - p[i].se)) mn = p[i];
	}
	rep(i, n) swap(p[i].fi, p[i].se);
	sort(all(p));
	mn = p[0], mx = p[0];
	repn(i, 1, n){
		ans = max(ans, dist(p[i], mn));
		ans = max(ans, dist(p[i], mx));
		if(p[i].se > mx.se && (p[i].fi - mx.fi) < (p[i].se - mx.se)) mx = p[i];
		if(p[i].se < mn.se && (p[i].fi - mn.fi) < (mn.se - p[i].se)) mn = p[i];
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
