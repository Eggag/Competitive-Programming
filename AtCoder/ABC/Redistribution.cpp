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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[2][2005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int s;
	cin >> s;
	int ans = 0;
	repn(i, 3, s + 1) dp[0][i] = 1;
	ans += dp[0][s];
	repn(i, 1, (s / 3) + 1){
		repn(j, 3, s + 1) repn(k, i * 3, s - j + 1) if(dp[1 - (i & 1)][k]){
			dp[i & 1][k + j] += dp[1 - (i & 1)][k];
			if(dp[i & 1][k + j] >= MOD) dp[i & 1][k + j] -= MOD;
		}
		ans += dp[i & 1][s];
		if(ans >= MOD) ans -= MOD;
		rep(j, 2005) dp[1 - (i & 1)][j] = 0;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
