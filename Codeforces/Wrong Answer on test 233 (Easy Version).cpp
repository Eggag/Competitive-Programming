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

ll dp[2][4010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	if(k == 1){
		cout << 0 << endl;
		return 0;
	}
	int z = 2005;
	dp[0][z] = 1LL;
	repn(i, 1, n + 1){
		int cr = i & 1, pr = 1 - cr;
		int nw = a[i], ol = (i == 1 ? a[n] : a[i - 1]);
		repn(j, 1, 4009){
			if(nw == ol) (dp[cr][j] += (dp[pr][j] * k) % MOD) %= MOD;
			else{
				(dp[cr][j + 1] += dp[pr][j]) %= MOD;
				(dp[cr][j - 1] += dp[pr][j]) %= MOD;
				(dp[cr][j] += (dp[pr][j] * (k - 2)) % MOD) %= MOD;
			}
		}
		rep(j, 4010) dp[pr][j] = 0LL;
	}
	ll ans = 0LL;
	repn(i, 1, 2005) (ans += dp[n & 1][z + i]) %= MOD;
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
