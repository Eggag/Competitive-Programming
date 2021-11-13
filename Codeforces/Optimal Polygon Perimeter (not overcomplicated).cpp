#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

set<int> st;

ll dist(pair<ll, ll> a, pair<ll, ll> b){
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

pi findLR(int ind){
	auto it = st.find(ind);
	int l = 0, r = 0;
	if(it == st.begin()) l = *(--st.end());
	else l = *(--it), it++;
	if(it == --st.end()) r = *(st.begin());
	else r = *(++it);
	return mp(l, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<ll, ll>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se, st.insert(i);
	vector<ll> res(n - 2, 0LL);
	ll r = -1e18, l = 1e18;
	ll u = -1e18, d = 1e18;
	rep(i, n){
		l = min(l, p[i].fi);
		r = max(r, p[i].fi);
		d = min(d, p[i].se);
		u = max(u, p[i].se);
	}
	vector<pair<ll, ll>> v;
	rep(i, n) if(p[i].fi == l || p[i].fi == r || p[i].se == u || p[i].se == d) v.pb(p[i]);
	rep(i, n) rep(j, v.size()) repn(k, j + 1, v.size()){
		ll cur = dist(p[i], v[j]) + dist(v[j], v[k]) + dist(v[k], p[i]);
		res[0] = max(res[0], cur);
	}
	repn(i, 1, n - 2) res[i] = 2 * (r - l + u - d);
	rep(i, n - 2) cout << res[i] << ' ';
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
