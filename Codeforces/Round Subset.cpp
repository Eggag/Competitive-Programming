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
const int mxN = 205;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[2][mxN][mxN * 30];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	repn(i, 1, n + 1){
		int cr = i & 1;
		int cnt2 = 0, cnt5 = 0;
		while(a[i] % 2 == 0) a[i] /= 2, cnt2++;
		while(a[i] % 5 == 0) a[i] /= 5, cnt5++;
		rep(j, k + 1){
			rep(l, mxN * 30) if(dp[cr ^ 1][j][l] != -1){
				dp[cr][j][l] = max(dp[cr][j][l], dp[cr ^ 1][j][l]);
				dp[cr][j + 1][l + cnt5] = max(dp[cr][j + 1][l + cnt5], dp[cr ^ 1][j][l] + cnt2);
			}
		}
		memset(dp[cr ^ 1], -1, sizeof(dp[cr ^ 1]));
	}
	int ans = 0;
	rep(i, mxN * 30) if(dp[(n & 1)][k][i] != -1){
		ans = max(ans, min(i, dp[(n & 1)][k][i]));
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
