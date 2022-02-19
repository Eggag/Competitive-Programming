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
	int n, m;
	cin >> m >> n;
	vector<vi> g(m, vi(n, 0));
	rep(i, m) rep(j, n) cin >> g[i][j];
	if(m < n){
		int ans = 1e9;
		rep(j, n){
			int mx = 0;
			rep(i, m) mx = max(mx, g[i][j]);
			ans = min(ans, mx);
		}
		cout << ans << '\n';
		return;
	}
	int l = 0, r = 1e9 + 5;
	while(l < r){
		int mid = (l + r + 1) / 2;
		int f = 0;
		vi ok(n, 0);
		rep(i, m){
			int cnt = 0;
			rep(j, n) if(g[i][j] >= mid) cnt++, ok[j] = 1;
			if(cnt > 1) f = 1;
		}
		rep(j, n) if(!ok[j]) f = 0;
		if(f) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
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
