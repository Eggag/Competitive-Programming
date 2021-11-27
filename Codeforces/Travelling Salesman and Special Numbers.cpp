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
const int MOD = 1e9 + 7;
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN][mxN][2]; //[index][total count][equal to n]
int cnt[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int k1;
	cin >> k1;
	int n = (int)(s.size());
	dp[0][0][0] = 1;
	dp[0][1][1] = 1;
	repn(i, 1, n){
		rep(j, i + 1) rep(k, 2){
			if(s[i] == '1'){
				(dp[i][j][0] += dp[i - 1][j][k]) %= MOD;
				(dp[i][j + 1][k] += dp[i - 1][j][k]) %= MOD;
			}
			else{
				(dp[i][j][k] += dp[i - 1][j][k]) %= MOD;
				if(!k) (dp[i][j + 1][k] += dp[i - 1][j][k]) %= MOD;
			}
		}
	}
	rep(j, mxN) rep(k, 2) (cnt[j] += dp[n - 1][j][k]) %= MOD;
	(cnt[1] += MOD - 1) %= MOD;
	ll ans = 0;
	repn(i, 1, mxN){
		int cr = i, op = 1;
		while(cr != 1){
			cr = __builtin_popcount(cr);
			op++;
		}
		if(op == k1) (ans += cnt[i]) %= MOD;
	}
	if(!k1) cout << 1 << '\n';
	else cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
