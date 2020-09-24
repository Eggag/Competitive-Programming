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

int g[55][55];
int dp[5005][55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k2;
	cin >> n >> k2;
	rep(i, n) rep(j, n) cin >> g[i][j];
	rep(i, 5005) rep(j, 55) rep(k, 55) dp[i][j][k] = 1e9;
	rep(i, n) rep(j, n) if(g[i][j] == 1) dp[1][i][j] = 0;
	repn(i, 2, k2 + 1){
		rep(j, n) rep(k, n) rep(j1, n) rep(k1, n) if(g[j][k] == i && g[j1][k1] == (i - 1)){
			dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j1][k1] + abs(j - j1) + abs(k - k1));
		}
	}
	int ans = 1e9;
	rep(i, n) rep(j, n) if(g[i][j] == k2) ans = min(ans, dp[k2][i][j]);
	if(ans == 1e9) ans = -1;
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
