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

ll solve(){
	int n;
	cin >> n;
	map<ll, ll> m;
	vector<pair<ll, ll>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	sort(all(p));
	ll ans = 0LL;
	rep(i, n){
		m[p[i].fi + p[i].se] = max(m[p[i].fi + p[i].se], m[p[i].fi] + p[i].se);
		m[p[i].fi] = max(m[p[i].fi], m[p[i].fi - p[i].se] + p[i].se);
		ans = max(m[p[i].fi + p[i].se], ans);
		ans = max(m[p[i].fi], ans);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
