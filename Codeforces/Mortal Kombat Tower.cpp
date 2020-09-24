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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][2];

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) rep(j, 2) dp[i][j] = 1e9;
	dp[0][0] = a[0];
	dp[1][0] = (a[0] + a[1]);
	repn(i, 1, n){
		//do 1
		dp[i][1] = min(dp[i][1], dp[i - 1][0]);
		if(i < n - 1) dp[i + 1][1] = min(dp[i + 1][1], dp[i - 1][0]);
		//do 0
		dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i]);
		if(i < n - 1) dp[i + 1][0] = min(dp[i + 1][0], dp[i - 1][1] + a[i] + a[i + 1]);
	}
	cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
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
