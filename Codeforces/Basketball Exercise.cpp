#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[2][100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	ll h[2][n];
	rep(i, 2) rep(j, n) cin >> h[i][j];
	rep(i, 2) rep(j, n) dp[i][j] = 0;
	//makes no sense to jump more than 2
	dp[0][0] = h[0][0];
	dp[1][0] = h[1][0];
	repn(i, 1, n){
		dp[1][i] = dp[0][i - 1] + h[1][i];
		dp[0][i] = dp[1][i - 1] + h[0][i];
		if(i > 1){
			dp[1][i] = max(dp[1][i], dp[0][i - 2] + h[1][i]);
			dp[0][i] = max(dp[0][i], dp[1][i - 2] + h[0][i]);
		}
	}
	cout << max(dp[1][n - 1], dp[0][n - 1]) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
