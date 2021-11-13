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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n);
	ll tot = 0LL;
	rep(i, n) cin >> a[i], tot += a[i];
	int m;
	cin >> m;
	vector<pair<ll, ll>> p(m);
	rep(i, m) cin >> p[i].fi >> p[i].se;
	sort(all(a));
	rep(i, m){
		ll ans = 9e18;
		auto it = lb(all(a), p[i].fi);
		if(it != a.end()) ans = min(ans, max(0LL, p[i].se - (tot - *it)));
		if(it != a.begin()){
			it--;
			ans = min(ans, (p[i].fi - *it) + max(0LL, p[i].se - (tot - *it)));
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
