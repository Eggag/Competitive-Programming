#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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
	int n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	ll ans = 9223372036854775806LL;
	rep(i, n) rep(j, n) rep(l, n) rep(m, n){
		if(!(p[i].se >= p[j].se && p[l].fi <= p[m].fi)) continue;
		int tot = 0;
		rep(o, n) if(p[o].fi >= p[l].fi && p[o].fi <= p[m].fi && p[o].se <= p[i].se && p[o].se >= p[j].se) tot++;
		if(tot >= k) ans = min(ans, (ll)((p[i].se - p[j].se) * (p[m].fi - p[l].fi)));

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
