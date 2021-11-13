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
const int mxN = 4e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int MOD = m;
	dp[n] = 1;
	for(int j = 2; j <= n; j++){
		int val = n / j;
		int l = (j + ((n - (val * j) + val - 1) / val)) - (n % j != 0);
		ll add = (dp[n] * (ll)(l - j + 1)) % MOD;
		(dp[val] += add) %= MOD;
		j = l;
	}
	ll tot = 1;
	for(int i = n - 1; i >= 1; i--){
		(dp[i] += tot) %= MOD;
		for(int j = 2; j <= i; j++){
			int val = i / j;
			int l = (j + ((i - (val * j) + val - 1) / val)) - (i % j != 0);
			ll add = (dp[i] * (ll)(l - j + 1)) % MOD;
			(dp[val] += add) %= MOD;
			j = l;
		}
		(tot += dp[i]) %= MOD;
	}
	cout << dp[1] % MOD << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
