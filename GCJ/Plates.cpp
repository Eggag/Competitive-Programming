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

int solve(){
	int n, k, p;
	cin >> n >> k >> p;
	int g[n + 1][k + 1];
	repn(i, 1, n + 1) rep(j, k) cin >> g[i][j];
	int dp[n + 1][p + 1];
	rep(i, n + 1) rep(j, p + 1) dp[i][j] = -1e9;
	dp[0][0] = 0;
	repn(i, 1, n + 1){ //index
		int sum = 0;
		rep(j, p + 1) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		rep(j, k){ //how many we take
			sum += g[i][j];
			rep(l, p + 1) if((j + l + 1) <= p){ //prev
				dp[i][l + j + 1] = max(dp[i][l + j + 1], dp[i - 1][l] + sum);
			}
		}	
	}
	return dp[n][p];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1) cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
