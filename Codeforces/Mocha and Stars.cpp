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
const int MOD = 998244353;
const int mxN = 55, mxM = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][mxM];
int cnt[mxM], ndp[mxM];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	repn(i, p[0].fi, p[0].se + 1) dp[0][i] = 1;
	repn(i, 1, m + 1){
		dp[0][i] += dp[0][i - 1];
		if(dp[0][i] >= MOD) dp[0][i] -= MOD;
	}
	repn(i, 1, n){
		repn(j, p[i].fi, m + 1){
			dp[i][j] = (dp[i - 1][j - p[i].fi] - ((j - p[i].se - 1 >= 0) ? dp[i - 1][j - p[i].se - 1] : 0) + MOD) % MOD;
		}
		repn(j, 1, m + 1){
			dp[i][j] += dp[i][j - 1];
			if(dp[i][j] >= MOD) dp[i][j] -= MOD;
		}
	}
	int ans = dp[n - 1][m];
	for(int x = 2; x <= m; x++){
		int m1 = m / x;
		rep(i, n) rep(j, m1 + 1) dp[i][j] = 0;
		int l = max(1, (p[0].fi + x - 1) / x);
		int r = p[0].se / x;
		repn(i, l, r + 1) dp[0][i] = 1;
		repn(i, 1, m1 + 1){
			dp[0][i] += dp[0][i - 1];
			if(dp[0][i] >= MOD) dp[0][i] -= MOD;
		}
		repn(i, 1, n){
			int l = max(1, (p[i].fi + x - 1) / x);
			int r = p[i].se / x;
			repn(j, l, m1 + 1){
				dp[i][j] = (dp[i - 1][j - l] - ((j - r - 1 >= 0) ? dp[i - 1][j - r - 1] : 0) + MOD) % MOD;
			}
			repn(j, 1, m1 + 1){
				dp[i][j] += dp[i][j - 1];
				if(dp[i][j] >= MOD) dp[i][j] -= MOD;
			}
		}
		cnt[x] = dp[n - 1][m1];
	}
	for(int i = m; i >= 2; i--){
		ndp[i] = cnt[i];
		repn(j, 2, m + 1){
			if(i * j > m) break;
			(ndp[i] -= (ndp[i * j] - MOD)) %= MOD;
		}
		ans -= ndp[i];
		(ans += MOD) %= MOD;
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
