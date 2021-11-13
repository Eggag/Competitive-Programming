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
const int mxN = 1e4 + 5;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[2][mxN][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, w, h;
	cin >> n >> w >> h;
	rep(i, h + 1) dp[0][0][i] = 1;	
	repn(i, 1, w + 1){
		int cr = i & 1, pr = !(i & 1);
		rep(j, n + 1) rep(k, h + 1) if(j + k <= n){
			(dp[cr][j + k][k] += dp[pr][j][h]) %= MOD;
		}
		rep(j, n + 1){
			repn(k, 1, h + 1) (dp[cr][j][k] += dp[cr][j][k - 1]) %= MOD;
		}
		memset(dp[pr], 0, sizeof(dp[pr]));
	}
	int ans = 0;
	rep(i, n + 1) (ans += dp[w & 1][i][h]) %= MOD;
	rep(i, h + 1) if(w * i <= n) ans--;
	(ans += MOD) %= MOD;
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
