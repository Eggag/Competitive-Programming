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
#define inf 0x3f3f3f3f
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][2];

int solve(){
	int x, y;
	string s;
	cin >> x >> y >> s;
	int n = s.size();
	memset(dp, inf, sizeof(dp));
	if(s[0] == 'J') dp[0][0] = 0;
	else if(s[0] == 'C') dp[0][1] = 0;
	else dp[0][0] = dp[0][1] = 0;
	repn(i, 1, n){
		rep(j, 2) rep(k, 2){
			if((!k && s[i] == 'C') || (k == 1 && s[i] == 'J')) continue;
			int cst = 0;
			if(j && !k) cst = x;
			else if(!j && k) cst = y;
			dp[i][k] = min(dp[i][k], dp[i - 1][j] + cst);
		}
	}
	return min(dp[n - 1][0], dp[n - 1][1]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1) cout << "Case #" << i << ": " << solve() << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
