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
const int mxN = 2005;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][mxN][2]; //0 is stress free

void solve(){
	int a, b;
	char c;
	cin >> a >> c >> b;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = dp[0][0][1] = 1;
	rep(i, a + 1) rep(j, b + 1){
		if(i < a){
			if((i + 1) <= j) (dp[i + 1][j][1] += dp[i][j][1]) %= MOD;
			if(i > j || (i >= j && !i && !j)) (dp[i + 1][j][0] += dp[i][j][0]) %= MOD;
		}
		if(j < b){
			if(i <= j) (dp[i][j + 1][1] += dp[i][j][1]) %= MOD;
			if(i > (j + 1)) (dp[i][j + 1][0] += dp[i][j][0]) %= MOD;
		}
	}
	cout << dp[a][b][0] << " " << dp[b][b][1] << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
