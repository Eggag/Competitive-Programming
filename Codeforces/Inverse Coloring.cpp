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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[2][mxN][mxN][2], cnt[mxN];
ll ndp[2][mxN];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	dp[1][1][1][0] = 1LL;
	dp[1][1][1][1] = 1LL;
	repn(i, 2, n + 1){
		int cr = i & 1, pr = 1 - cr;
		repn(mx, 1, i) repn(nw, 1, i) rep(j, 2) rep(l, 2){
			if(j == l){
				(dp[cr][max(nw + 1, mx)][nw + 1][l] += dp[pr][mx][nw][j]) %= MOD;
			}
			else (dp[cr][mx][1][l] += dp[pr][mx][nw][j]) %= MOD;
		}
		memset(dp[pr], 0, sizeof(dp[pr]));
	}
	repn(i, 1, n + 1) repn(cr, 1, n + 1) rep(j, 2) (cnt[i] += dp[n & 1][i][cr][j]) %= MOD;
	ll ans = 0LL;
	repn(i, 1, n + 1) if(cnt[i]){
		int mx = (k + i - 1) / i;
		mx = min(mx, n + 1);
		memset(ndp, 0, sizeof(ndp));
		ndp[1][1] = 1LL;
		repn(j, 2, n + 1){
			int cr = j & 1, pr = 1 - cr;
			repn(nw, 1, min(mx, j)) rep(l, 2){
				if(!l){
					if(nw < (mx - 1)) (ndp[cr][nw + 1] += ndp[pr][nw]) %= MOD;
				}
				else (ndp[cr][1] += ndp[pr][nw]) %= MOD;
			}
			memset(ndp[pr], 0, sizeof(ndp[pr]));
		}
		ll mul = 0LL;
		repn(nw, 1, mx) (mul += ndp[n & 1][nw]) %= MOD;
		(ans += (ll)(1LL * mul * cnt[i]) % MOD) %= MOD;
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
