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

ll dp[201][51][51][51]; //[turn][nf1][nf][f];
ll c[51][51];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, K;
	cin >> n >> K;
	int f = 0, nf = 0;
	rep(i, n){
		int x;
		cin >> x;
		if(x == 100) f++;
		else nf++;
	}
	c[0][0] = 1;
	repn(i, 1, 51){
		c[i][0] = c[i][i] = 1;
		repn(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0][nf][f] = 1;
	rep(i, 164){
		if(~dp[i][nf][0][0]){
			cout << i << endl << dp[i][nf][0][0] << endl;
			return 0;
		}
		rep(j, n + 1) rep(k, n + 1) rep(l, n + 1) if(~dp[i][j][k][l] && (j + k) == nf && l <= f){
			int m = f - l;
			if(i & 1){
				//we go ->
				rep(i1, j + 1) rep(j1, m + 1) if((i1 * 50 + j1 * 100) <= K && (i1 + j1) > 0){
					ll nmw = (c[j][i1] * c[m][j1]) % MOD;
					if(dp[i + 1][j - i1][k + i1][l + j1] == -1) dp[i + 1][j - i1][k + i1][l + j1] = 0LL;
					(dp[i + 1][j - i1][k + i1][l + j1] += (dp[i][j][k][l] * nmw) % MOD) %= MOD;
				}
			}
			else{
				//we go <-
				rep(i1, k + 1) rep(j1, l + 1) if((i1 * 50 + j1 * 100) <= K && (i1 + j1) > 0){
					ll nmw = (c[k][i1] * c[l][j1]) % MOD;
					if(dp[i + 1][j + i1][k - i1][l - j1] == -1) dp[i + 1][j + i1][k - i1][l - j1] = 0LL;
					(dp[i + 1][j + i1][k - i1][l - j1] += (dp[i][j][k][l] * nmw) % MOD) %= MOD;
				}
			}
		}
	}
	cout << "-1\n0\n";
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
