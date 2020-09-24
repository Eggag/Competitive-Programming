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
const int MOD = 1e6 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[1005][1005][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	rep(i, 1005) rep(j, 1005) rep(k, 2) dp[i][j][k] = 0;
	dp[0][1][1] = 1;
	dp[0][1][0] = 0;
	repn(i, 1, n){
		repn(k, 1, i + 2){
			repn(j, 1, i + 1) if((k - 1) <= j){
				if(k < a[i]){
					//we can make a 1 into a 0
					dp[i][max(j, k)][0] = (dp[i][max(j, k)][0] + dp[i - 1][j][1]) % MOD;
				}
				//update the 0 guy
				dp[i][max(j, k)][0] = (dp[i][max(j, k)][0] + dp[i - 1][j][0]) % MOD;
				if(k == a[i]) dp[i][max(j, k)][1] = (dp[i][max(j, k)][1] + dp[i - 1][j][1]) % MOD;
			}
		}
	}
	ll ans = 0;
	repn(i, 1, n + 1) ans = (ans + dp[n - 1][i][0]) % MOD;
	cout << ans + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
