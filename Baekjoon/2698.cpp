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

void solve(){
	int n, k;
	cin >> n >> k;
	if(n == 1){
		cout << 0 << endl;
		return;
	}
	rep(i, 105) rep(j, 105) rep(k1, 2) dp[i][j][k1] = 0;
	dp[2][1][1] = 1;
	dp[2][0][0] = 2;
	dp[2][0][1] = 1;
	repn(i, 3, n + 1){
		rep(j, k + 1){
			dp[i][j][0] += dp[i - 1][j][1] + dp[i - 1][j][0];
			if(j) dp[i][j][1] = dp[i - 1][j - 1][1];
			dp[i][j][1] += dp[i - 1][j][0];
		}
	}
	cout << dp[n][k][0] + dp[n][k][1] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
