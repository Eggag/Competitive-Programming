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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN][3][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n + 1, 0LL);
	rep(i, n) cin >> a[i];
	rep(i, mxN) rep(j, 3) rep(k, 3) dp[i][j][k] = -1e18;
	dp[0][0][0] = 0LL;
	rep(i, n + 1) rep(j, 3) rep(k, 3){
		if(k < 2) dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
		if(j < 2) dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
		if(i < n){
			dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + (j == 1 ? a[i] : 0LL) * (k == 1 ? x : 1LL));
		}
	}
	cout << dp[n][2][2] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
