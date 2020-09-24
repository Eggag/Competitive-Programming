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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[4][10000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	repn(i, 1, n + 1){
		dp[0][i] += dp[1][i - 1];
		if(dp[0][i] >= MOD) dp[0][i] %= MOD;
		dp[0][i] += dp[2][i - 1];
		if(dp[0][i] >= MOD) dp[0][i] %= MOD;
		dp[0][i] += dp[3][i - 1];
		if(dp[0][i] >= MOD) dp[0][i] %= MOD;
		dp[1][i] += dp[0][i - 1];
		if(dp[1][i] >= MOD) dp[1][i] %= MOD;
		dp[1][i] += dp[2][i - 1];
		if(dp[1][i] >= MOD) dp[1][i] %= MOD;
		dp[1][i] += dp[3][i - 1];
		if(dp[1][i] >= MOD) dp[1][i] %= MOD;
		dp[2][i] += dp[1][i - 1];
		if(dp[2][i] >= MOD) dp[2][i] %= MOD;
		dp[2][i] += dp[0][i - 1];
		if(dp[2][i] >= MOD) dp[2][i] %= MOD;
		dp[2][i] += dp[3][i - 1];
		if(dp[2][i] >= MOD) dp[2][i] %= MOD;
		dp[3][i] += dp[1][i - 1];
		if(dp[3][i] >= MOD) dp[3][i] %= MOD;
		dp[3][i] += dp[2][i - 1];
		if(dp[3][i] >= MOD) dp[3][i] %= MOD;
		dp[3][i] += dp[0][i - 1];
		if(dp[3][i] >= MOD) dp[3][i] %= MOD;
	}
	cout << dp[0][n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
