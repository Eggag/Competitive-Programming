#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int MOD = 1e8;

int dp[105][105][2][15];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	dp[1][0][0][1] = 1;
	dp[0][1][1][1] = 1;
	repn(i, 0, n1 + 1) repn(j, 0, n2 + 1){
		repn(k, 1, k1 + 1){
			(dp[i + 1][j][0][k + 1] += dp[i][j][0][k]) %= MOD;
			(dp[i][j + 1][1][1] += dp[i][j][0][k]) %= MOD;
		}	
		repn(k, 1, k2 + 1){
			(dp[i][j + 1][1][k + 1] += dp[i][j][1][k]) %= MOD;
			(dp[i + 1][j][0][1] += dp[i][j][1][k]) %= MOD;
		}
	}
	int ans = 0;
	repn(k, 1, k1 + 1){
		ans = (ans + dp[n1][n2][0][k]) % MOD;
	}
	repn(k, 1, k2 + 1){
		ans = (ans + dp[n1][n2][1][k]) % MOD;
	}
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
