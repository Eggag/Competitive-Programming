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

bool cmp1(pi a, pi b){
	return a.se < b.se;
}

void solve(){
	int n;
	cin >> n;
	vector<pi> p(n), p1(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	rep(i, n) p1[i] = p[i];
	sort(all(p));
	sort(all(p1), cmp1);
	int l = 0;
	int ans = 1e9;
	rep(i, n){
		while(l < n && p1[l].se < p[i].fi) l++;
		auto sg = lb(all(p), mp(p[i].se + 1, 0));
		int nm = n - (sg - p.begin());
		ans = min(ans, l + nm);
	}
	cout << ans << endl;
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
