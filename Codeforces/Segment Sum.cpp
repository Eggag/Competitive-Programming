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

ll l, r, k;
int dp[20][2][1 << 11];
int dp1[20][1 << 11];
ll powt[20];

ll solve(ll g){
	string s = to_string(g);
	int n = s.size();
	ll ans = 0LL;
	repn(p, 1, n + 1) repn(d, 1, 10){
		ll add = (1LL * d * powt[n - p]) % MOD;
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		repn(i, 1, n + 1){
			int le = 0, ri = 10;
			if(i == p) le = d, ri = d + 1;
			rep(j, 1 << 10) repn(k, le, ri) if(dp[i - 1][0][j] || dp[i - 1][1][j]){
				if(i == 1 && !k) continue;
				//dp[i - 1][j] to dp[i][j | 1 << k] 
				int cr = s[i - 1] - '0';
				if(cr == k){
					//0 to 0
					(dp[i][0][j | (1 << k)] += dp[i - 1][0][j]) %= MOD;
					//1 to 1
					(dp[i][1][j | (1 << k)] += dp[i - 1][1][j]) %= MOD;
				}
				else if(cr > k){
					//1 to 1
					(dp[i][1][j | (1 << k)] += dp[i - 1][1][j]) %= MOD;
					//0 to 1
					(dp[i][1][j | (1 << k)] += dp[i - 1][0][j]) %= MOD;
				}
				else{
					//1 to 1
					(dp[i][1][j | (1 << k)] += dp[i - 1][1][j]) %= MOD;
				}
			}
		}
		rep(i, 1 << 10){
			if(__builtin_popcount(i) <= k){
				(ans += (((dp[n][0][i] + dp[n][1][i]) % MOD) * add) % MOD) %= MOD;
			}
		}
	}
	repn(len, 1, n) repn(p, 1, len + 1) repn(d, 1, 10){
		ll add = (1LL * d * powt[len - p]) % MOD;
		memset(dp1, 0, sizeof(dp1));
		dp1[0][0] = 1;
		repn(i, 1, len + 1){
			int le = 0, ri = 10;
			if(i == p) le = d, ri = d + 1;
			rep(j, 1 << 10) repn(k, le, ri) if(dp1[i - 1][j] || dp1[i - 1][j]){
				if(i == 1 && !k) continue;
				(dp1[i][j | (1 << k)] += dp1[i - 1][j]) %= MOD;
			}
		}
		rep(i, 1 << 10){
			if(__builtin_popcount(i) <= k){
				(ans += (dp1[len][i] * add) % MOD) %= MOD;
			}
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> l >> r >> k;
	powt[0] = 1LL;
	repn(i, 1, 20) powt[i] = (1LL * 10 * powt[i - 1]) % MOD;
	cout << (solve(r) - solve(l - 1) + MOD) % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
