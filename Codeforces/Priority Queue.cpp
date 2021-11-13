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

ll dp[mxN][mxN];
ll C[mxN][mxN];

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
	int n;
	cin >> n;
	int cnt = 0;
	vector<pair<ll, int>> p;
	rep(i, n){
		char c;
		cin >> c;
		if(c == '-') cnt++;
		else{
			ll x;
			cin >> x;
			p.pb(mp(x, cnt));
			cnt = 0;
		}
	}
	if(!p.size()){
		cout << 0 << '\n';
		return 0;
	}
	rep(i, mxN){
		C[i][0] = C[i][i] = 1LL;
		repn(j, 1, i){
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	ll st = (ll)(p[0].se);
	rep(i, (int)(p.size()) - 1) p[i].se = p[i + 1].se;
	p[(int)(p.size()) - 1].se = cnt;
	ll ans = 0LL;
	rep(i, p.size()){
		memset(dp, 0, sizeof(dp));
		array<ll, 2> dp1 = {0, 0};
		if(i){
			if(p[0].fi <= p[i].fi){
				dp1[0] = 1;
				dp1[1] = 1;
			}
			else dp1[0] = 2;
		}
		else dp1[0] = 1;
		if(!i){
			rep(k, 2){
				rep(l, p[0].se + 1) if(k >= l){
					(dp[0][k - l] += (dp1[k] * C[p[0].se][l]) % MOD) %= MOD;
				}
			}
		}
		else{
			rep(k, 2){
				rep(l, p[0].se + 1){
					(dp[0][max(0, k - l)] += (dp1[k] * C[p[0].se][l]) % MOD) %= MOD;
				}
			}
		}
		repn(j, 1, p.size()){
			if(j < i){
				rep(k, j + 1) if(dp[j - 1][k]){
					rep(l, p[j].se + 1){
						int f = 0;
						if(p[j].fi <= p[i].fi) f = 1;
						if(f){
							(dp[j][max(0, k + 1 - l)] += ((dp[j - 1][k] % MOD) * C[p[j].se][l]) % MOD) %= MOD;
							(dp[j][max(0, k - l)] += ((dp[j - 1][k] % MOD) * C[p[j].se][l]) % MOD) %= MOD;
						}
						else (dp[j][max(0, k - l)] += (2 * dp[j - 1][k] * C[p[j].se][l]) % MOD) %= MOD;
					}
				}
			}
			else{
				rep(k, j + 1) if(dp[j - 1][k]){
					rep(l, p[j].se + 1){
						int f = 0;
						if(p[j].fi < p[i].fi) f = 1;
						if(f){
							if(k + 1 >= l) (dp[j][k + 1 - l] += ((dp[j - 1][k] % MOD) * C[p[j].se][l]) % MOD) %= MOD;
							if(k >= l) (dp[j][k - l] += ((dp[j - 1][k] % MOD) * C[p[j].se][l]) % MOD) %= MOD;
						}
						else if(k >= l){
							(dp[j][k - l] += ((j == i ? 1 : 2) * dp[j - 1][k] * C[p[j].se][l]) % MOD) %= MOD;
						}
					}
				}
			}
		}
		ll cur = 0LL;
		rep(j, p.size()) (cur += (dp[(int)(p.size()) - 1][j]) % MOD) %= MOD;
		(ans += (cur * (ll)(p[i].fi)) % MOD) %= MOD;
	}
	cout << (ans * mypow(2, st)) % MOD << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
