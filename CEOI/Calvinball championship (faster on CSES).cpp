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
const int MOD = 1e6 + 7;
const int mxN = 1e4 + 5;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
int dp[2][mxN][2];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	memset(dp, 0, sizeof(dp));
	dp[0][1][1] = 1;
	dp[0][1][0] = 0;
	repn(i, 1, n){
		int cur = i & 1, prev = 1 - cur;
		repn(j, 1, i + 1){
			//turn a 1 into a 0
			ll nm = min(j, a[i] - 1); //the number that satisfies the condition
			(dp[cur][j][0] += (ll)(dp[prev][j][1] * nm) % MOD) %= MOD;
			if((j + 1) < a[i]) (dp[cur][j + 1][0] += dp[prev][j][1] % MOD) %= MOD;
			//update the 0 guy
			ll nm1 = j;
			(dp[cur][j][0] += (ll)(dp[prev][j][0] * nm1) % MOD) %= MOD;
			(dp[cur][j + 1][0] += dp[prev][j][0]) %= MOD;
			//update the 1 guy
			(dp[cur][max(j, a[i])][1] += dp[prev][j][1]) %= MOD;
		}
		memset(dp[prev], 0, sizeof(dp[prev]));
	}
	ll ans = 0;
	repn(i, 1, n + 1) ans = (ans + dp[(n - 1) & 1][i][0]) % MOD;
	cout << ans + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
