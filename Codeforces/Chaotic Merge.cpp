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
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][mxN][2][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string x, y;
	cin >> x >> y;
	int n = (int)(x.size()), m = (int)(y.size());
	rep(i, n + 1) rep(j, m + 1){
		if(i) (dp[i][j][0][0] += 1) %= MOD;
		if(j) (dp[i][j][1][1] += 1) %= MOD;
		rep(k, 2) rep(l, 3){
			int k1 = 0;
			if(!k){
				if(i) k1 = x[i - 1] - 'a';
				else continue;
			}
			else{
				if(j) k1 = y[j - 1] - 'a';
				else continue;
			}
			if(i < n && k1 != (x[i] - 'a')){
				int l1 = ((l + 1) | 1) - 1;
				(dp[i + 1][j][0][l1] += dp[i][j][k][l]) %= MOD;
			}
			if(j < m && k1 != (y[j] - 'a')){
				int l1 = ((l + 1) | 2) - 1;
				(dp[i][j + 1][1][l1] += dp[i][j][k][l]) %= MOD;
			}
		}
	}
	int ans = 0;
	rep(i, n + 1) rep(j, m + 1) rep(k, 2) (ans += dp[i][j][k][2]) %= MOD;
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
