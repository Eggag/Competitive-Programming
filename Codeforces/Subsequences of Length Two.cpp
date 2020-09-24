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
const int mxN = 205;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][mxN][mxN]; //[index][number of t[0]][changes]

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, K;
	cin >> n >> K;
	string s, t;
	cin >> s >> t;
	rep(i, mxN) rep(j, mxN) rep(k, mxN) dp[i][j][k] = -1e9;
	dp[0][0][0] = 0;
	repn(i, 1, n + 1){
		rep(j, i) rep(k, min(K + 1, i)) rep(l, 3){
			char cur = s[i - 1];
			if(l == 0 && k < K){
				cur = t[0];
				dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i - 1][j][k] + (cur == t[1] ? j : 0));
			}
			if(l == 1 && k < K){
				cur = t[1];
				dp[i][j + (cur == t[0])][k + 1] = max(dp[i][j + (cur == t[0])][k + 1], dp[i - 1][j][k] + j);
			}
			if(l == 2){
				dp[i][j + (cur == t[0])][k] = max(dp[i][j + (cur == t[0])][k], dp[i - 1][j][k] + (cur == t[1] ? j : 0));
			}
		}
	}
	int ans = 0;
	rep(i, n + 1) rep(j, n + 1) rep(k, K + 1) ans = max(ans, dp[i][j][k]);
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
