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
const int mxN = 405;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int MOD;
ll dp[mxN][mxN];
ll fact[mxN];
ll invFact[mxN];
ll dp1[mxN];

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1) % MOD)) % MOD;
	ll x = mypow(a, p / 2) % MOD;
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
	int n;
	cin >> n >> MOD;
	memset(dp, 0, sizeof(dp));
	invFact[0] = 1;
	fact[0] = 1;
	for(ll i = 1LL; i < mxN; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
	for(ll i = mxN - 1; i >= 0LL; i--){
		if(i == (mxN - 1)) invFact[i] = inv(fact[i]);
		else invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
	}
	repn(i, 1, n + 1){
		rep(l, i){
			ll cur = (fact[l + (i - l - 1)] * invFact[l]) % MOD;
			(cur *= invFact[i - l - 1]) %= MOD;
			(dp1[i] += cur) %= MOD;
		}
	}
	rep(i, n){
		if(!i){
			repn(k, i, n){
				(dp[k][(k - i + 1)] += dp1[k - i + 1]) %= MOD;
			}
		}
		else if(i > 1){
			rep(j, n + 1){
				ll pr = dp[i - 2][j];
				repn(k, i, n){
					ll add = pr;	
					(add *= dp1[k - i + 1]) %= MOD;
					(add *= (fact[j + (k - i + 1)] * invFact[j]) % MOD) %= MOD;
					(add *= invFact[k - i + 1] % MOD) %= MOD;
					(dp[k][j + (k - i + 1)] += add) %= MOD;
				}
			}
		}
	}
	ll ans = 0LL;
	rep(i, n + 1){
		(ans += dp[n - 1][i]) %= MOD;
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
