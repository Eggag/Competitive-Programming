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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[105][105][2];
int ans[105][105];

void precompute(){
	rep(i, 105) rep(j, 105) rep(k1, 2) dp[i][j][k1] = 0;
	dp[2][1][1] = 1;
	dp[2][0][0] = 2;
	dp[2][0][1] = 1;
	repn(i, 3, 105){
		rep(j, 105){
			dp[i][j][0] += dp[i - 1][j][1] + dp[i - 1][j][0];
			if(j) dp[i][j][1] = dp[i - 1][j - 1][1];
			dp[i][j][1] += dp[i - 1][j][0];
			ans[i][j] = dp[i][j][0] + dp[i][j][1];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	rep(i, 105) rep(j, 105) ans[i][j] = 0;
	precompute();
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << ans[n][k] << endl;
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
