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

int dp[200005][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	dp[0][1] = 1;
	int ans = 0;
	repn(i, 1, n){
		dp[i][0] = 1;
		dp[i][1] = 1;
		if(a[i] > a[i - 1]){
			dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
			dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
		}
		if(i >= 2 && a[i] > a[i - 2]) dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
		ans = max(ans, dp[i - 1][0]);
	}
	rep(i, n) ans = max({ans, dp[i][0], dp[i][1]});
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
