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

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	vector<pi> p;
	rep(i, n / 2) p.pb({a[i], a[n - i - 1]});
	vi cnt(2 * k + 2, 0);
	rep(i, n / 2){
		int sum = p[i].fi + p[i].se;
		int mn = k - min(p[i].fi, p[i].se);
		int mx = max(p[i].fi, p[i].se) - 1;
		cnt[0] += 2;
		cnt[2 * k + 1] -= 2;
		cnt[sum] -= 2;
		cnt[sum + 1] += 2;
		cnt[sum - mx] -= 1;
		cnt[sum + mn + 1] += 1;
		cnt[sum] += 1;
		cnt[sum + 1] -= 1;

	}
	partial_sum(all(cnt), cnt.begin());
	int ans = 1e9;
	repn(i, 2, 2 * k + 1) ans = min(ans, cnt[i]);
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
	- Array bounds
	- Special cases
Be careful!
*/
