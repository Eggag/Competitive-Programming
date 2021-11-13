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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][26][2];

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	repn(i, 1, ((n + 1) / 2) + 1){
		rep(j, k) rep(l, k){
			char c = (char)('a' + l);
			(dp[i][l][1] += dp[i - 1][j][1]) %= MOD;
			if(c == s[i - 1]) (dp[i][l][0] += dp[i - 1][j][0]) %= MOD;
			if(c < s[i - 1]) (dp[i][l][1] += dp[i - 1][j][0]) %= MOD;
		}
	}
	int ans = 0, ans1 = 0;
	rep(j, k){
		(ans += dp[(n + 1) / 2][j][1]) %= MOD;
		(ans1 += dp[(n + 1) / 2][j][0]) %= MOD;
	}
	string s1 = s.substr(0, n / 2);
	string s2 = s1;
	reverse(all(s2));
	if(n & 1) s1 += s[n / 2];
	s1 += s2;
	if(s1 < s) (ans += ans1) %= MOD;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
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
