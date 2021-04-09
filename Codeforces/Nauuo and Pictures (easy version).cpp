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
const int MOD = 998244353;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[2][115][115][115];

ll mypow(ll a, ll p){
	if(p <= 0) return 1LL;
	if(p & 1) return (mypow(a, p - 1) * a) % MOD;
	ll x = mypow(a, p / 2);
	return (x * x) % MOD;
}

ll inv(ll a){
	return mypow(a, MOD - 2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), w(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> w[i];
	rep(i, n){
		memset(dp, 0, sizeof(dp));
		dp[0][55][55][55] = 1;
		ll tot = 0, tot2 = 0;
		rep(j, n) if(j != i){
			if(a[j]) tot += w[j];
			else tot2 += w[j];
		}
		repn(j, 1, m + 1){
			int cr = j & 1, pr = 1 - cr;
			for(int k = 55 - (j + 1); k <= 55 + (j + 1); k++)
			for(int l = 55 - (j + 1); l <= 55 + (j + 1); l++)
			for(int p = 55 - (j + 1); p <= 55 + (j + 1); p++) if(dp[pr][k][l][p]){
				ll w1 = w[i] + k - 55;
				ll tot1 = tot + l - 55;
				ll tot3 = tot2 + p - 55;
				if(a[i]){
					tot1 = tot + p - 55;
					tot3 = tot2 + l - 55;
				}
				ll sum = w1 + tot1 + tot3;
				if(a[i]){
					ll nw = (((dp[pr][k][l][p] * w1) % MOD) * inv(sum)) % MOD;
					(dp[cr][k + 1][l][p] += nw) %= MOD;
					nw = (((dp[pr][k][l][p] * tot3) % MOD) * inv(sum)) % MOD;
					(dp[cr][k][l - 1][p] += nw) %= MOD;
					nw = (((dp[pr][k][l][p] * tot1) % MOD) * inv(sum)) % MOD;
					(dp[cr][k][l][p + 1] += nw) %= MOD;
				}
				else{
					ll nw = (((dp[pr][k][l][p] * w1) % MOD) * inv(sum)) % MOD;
					(dp[cr][k - 1][l][p] += nw) %= MOD;
					nw = (((dp[pr][k][l][p] * tot1) % MOD) * inv(sum)) % MOD;
					(dp[cr][k][l + 1][p] += nw) %= MOD;
					nw = (((dp[pr][k][l][p] * tot3) % MOD) * inv(sum)) % MOD;
					(dp[cr][k][l][p - 1] += nw) %= MOD;
				}
			}
			memset(dp[pr], 0, sizeof(dp[pr]));
		}
		ll ans = 0LL;
		rep(k, 115) rep(l, 115) rep(p, 115) if(dp[m & 1][k][l][p]){
			(ans += ((w[i] + k - 55) * dp[m & 1][k][l][p]) % MOD) %= MOD;
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
