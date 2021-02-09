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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[1005][100][2][2];
int powt[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k, m;
	cin >> n >> k >> m;
	dp[0][0][0][0] = 1;
	powt[0] = 1LL;
	repn(i, 1, 1005) powt[i] = (10 * powt[i - 1]) % k;
	repn(i, 1, n + 1){
		repn(j, (i == n ? 1 : 0), 10){
			rep(l, 100){
				int tot = (l + (powt[i - 1] * j)) % k;
				(dp[i][tot][1][1] += dp[i - 1][l][1][1]) %= m;
				if(!tot){
					if(j) (dp[i][tot][1][1] += dp[i - 1][l][0][0]) %= m;
					else (dp[i][tot][0][0] += dp[i - 1][l][0][0]) %= m;
					(dp[i][tot][1][1] += dp[i - 1][l][0][1]) %= m;
				}
				else{
					if(j) (dp[i][tot][0][1] += dp[i - 1][l][0][0]) %= m;
					(dp[i][tot][0][1] += dp[i - 1][l][0][1]) %= m;
				}
			}
		}
	}
	int ans = 0;
	rep(i, k) (ans += dp[n][i][1][1]) %= m;
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
