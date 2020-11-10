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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	memset(dp, inf, sizeof(dp));
	dp[0][a[0] + 1] = 0;
	repn(i, 1, n){
		if(a[i] == -1){
			dp[i][0] = dp[i - 1][0];
			dp[i][2] = dp[i - 1][2] + 2;
		}
		else if(!a[i]){
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = min({dp[i - 1][1], dp[i - 1][0]});
			dp[i][2] = dp[i - 1][2] + 1;
		}
		else{
			dp[i][0] = dp[i - 1][0] + 2;
			dp[i][1] = dp[i - 1][0] + 1;
			dp[i][2] = min({dp[i - 1][2], dp[i - 1][1], dp[i - 1][0]});
		}
	}
	int ans = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
	if(ans >= inf) cout << "BRAK" << endl;
	else cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
