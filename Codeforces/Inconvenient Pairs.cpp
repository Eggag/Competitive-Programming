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

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vi x(n), y(m);
	rep(i, n) cin >> x[i];
	rep(i, m) cin >> y[i];
	vector<pi> p(k);
	rep(i, k) cin >> p[i].fi >> p[i].se;
	sort(all(p));
	ll ans = 0LL;
	int l = 0;
	x.pb(1e6);
	rep(i, n + 1){
		int lst = (i ? x[i - 1] : 0);
		while(l < k && p[l].fi == lst) l++;
		int fst = l;
		while(l < k && p[l].fi > lst && p[l].fi < x[i]) l++;
		vi cr;
		repn(j, fst, l) cr.pb(p[j].se);
		sort(all(cr));
		int tot = (int)(cr.size());
		if(!tot) continue;
		int nm = 1;
		ll nw = 0LL;
		repn(j, 1, cr.size()){
			if(cr[j] == cr[j - 1]) nm++;
			else{
				nw += 1LL * (ll)(nm) * (ll)(tot - nm);
				nm = 1;
			}
		}
		nw += 1LL * (ll)(nm) * (ll)(tot - nm);
		ans += nw / 2;
	}
	x = y;
	n = m;
	x.pb(1e6);
	l = 0;
	rep(i, k) swap(p[i].fi, p[i].se);
	sort(all(p));
	rep(i, n + 1){
		int lst = (i ? x[i - 1] : 0);
		while(l < k && p[l].fi == lst) l++;
		int fst = l;
		while(l < k && p[l].fi > lst && p[l].fi < x[i]) l++;
		vi cr;
		repn(j, fst, l) cr.pb(p[j].se);
		sort(all(cr));
		int tot = (int)(cr.size());
		if(!tot) continue;
		int nm = 1;
		ll nw = 0LL;
		repn(j, 1, cr.size()){
			if(cr[j] == cr[j - 1]) nm++;
			else{
				nw += 1LL * (ll)(nm) * (ll)(tot - nm);
				nm = 1;
			}
		}
		nw += 1LL * (ll)(nm) * (ll)(tot - nm);
		ans += nw / 2;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
