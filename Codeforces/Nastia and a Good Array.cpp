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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n;
	cin >> n;
	vector<pi> a(n);
	rep(i, n) cin >> a[i].fi, a[i].se = i;
	sort(all(a));
	vector<array<int, 4>> ans;
	repn(i, 1, n){
		array<int, 4> cr = {0, 0, 0, 0};
		cr[0] = a[0].se + 1, cr[1] = a[i].se + 1;
		cr[2] = a[0].fi;
		cr[3] = a[0].fi + abs(a[i].se - a[0].se);
		ans.pb(cr);
	}
	cout << (int)(ans.size()) << '\n';
	for(array<int, 4> x : ans) cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << '\n';
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
