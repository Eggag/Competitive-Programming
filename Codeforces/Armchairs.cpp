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
#define inf 0x3f3f3f3f
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), on, of;
	rep(i, n){
		cin >> a[i];
		if(a[i]) on.pb(i);
		else of.pb(i);
	}
	n = (int)(of.size());
	int m = (int)(on.size());
	if(!n){
		cout << "0\n";
		return 0;
	}
	memset(dp, inf, sizeof(dp));
	dp[0][0] = 0;
	rep(i, n) rep(j, m + 1){
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		if(j != m) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(of[i] - on[j]));
	}	
	cout << dp[n][m] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
