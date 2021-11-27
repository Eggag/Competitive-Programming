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
const int mxN = 405;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[105][35][35][1 << 9];

ll fact[mxN];
ll invFact[mxN];

ll C(ll n, ll r){
	if(r > n) return 0;
	ll ret = fact[n];
	ret = ((ret * invFact[n - r]) + MOD) % MOD;
	ret = ((ret * invFact[r]) + MOD) % MOD;
	return ret;
}

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1) % MOD)) % MOD;
	ll x = mypow(a, p / 2) % MOD;
	return (x * x) % MOD;
}

ll inv(ll base){
	return mypow(base, MOD - 2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> v(m + 1);
	rep(i, m + 1) cin >> v[i];
	invFact[0] = 1;
	fact[0] = 1;
	for(ll i = 1LL; i < mxN; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
	for(ll i = mxN - 1; i >= 0LL; i--){
		if(i == (mxN - 1)) invFact[i] = inv(fact[i]);
		else invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
	}
	rep(i, m + 1){
		if(!i){
			ll nm = 1;
			rep(g, n + 1){
				(dp[i][(g & 1)][g][g >> 1] += nm) %= MOD;
				(nm *= v[i]) %= MOD;
			}
		}
		else{
			rep(j, k + 1) rep(h, n + 1) rep(l, 1 << 9) if(dp[i - 1][j][h][l]){
				ll nm = 1;
				rep(g, n + 1){
					if(h + g > n) break;
					int msk = l + g;
					int n1 = g, k1 = h + 1;
					(dp[i][j + (msk & 1)][h + g][msk >> 1] += (C(n1 + k1 - 1, k1 - 1) * ((nm * dp[i - 1][j][h][l]) % MOD)) % MOD) %= MOD;
					(nm *= v[i]) %= MOD;
				}
			}
		}
	}
	ll ans = 0;
	rep(j, k + 1) rep(l, 1 << 9){
		if(j + __builtin_popcount(l) <= k) (ans += dp[m][j][n][l] % MOD) %= MOD;
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
