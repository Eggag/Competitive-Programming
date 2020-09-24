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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[8][3][2];
int c[3][150005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, 3) rep(j, n) cin >> c[i][j];
	rep(i, 8) rep(k, 3) rep(j, 2) dp[i][k][j] = 1e9;
	dp[1][0][0] = c[0][0];
	dp[2][1][0] = c[1][0];
	dp[4][2][0] = c[2][0];
	repn(i, 1, n){
		int cur = i & 1;
		int prev = 1 - cur;
		rep(j, 3) repn(k, 1, 8) dp[k][j][cur] = 1e9;
		rep(j, 3) repn(k, 1, 8) if(k & (1 << j)) dp[k][j][cur] = dp[k][j][prev] + c[j][i];
		rep(j, 3) rep(l, 3) repn(k, 1, 8) if(!(k & (1 << j)) && (k & (1 << l))){
			dp[k | (1 << j)][j][cur] = min(dp[k | (1 << j)][j][cur], dp[k][l][prev] + c[j][i]);
		}
	}
	int cur = (n - 1) & 1;
	cout << min({dp[7][0][cur], dp[7][1][cur], dp[7][2][cur]}) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
