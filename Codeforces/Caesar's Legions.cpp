#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second
const int MOD = 1e8;

int dp[110][110][2][11];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	dp[1][0][0][1] = 1;
	dp[0][1][1][1] = 1;
	for(int i = 0; i <= n1; i++){
		for(int j = 0; j <= n2; j++){
			for(int k = 1; k <= k1; k++){
				(dp[i + 1][j][0][k + 1] += dp[i][j][0][k]) %= MOD;
				(dp[i][j + 1][1][1] += dp[i][j][0][k]) %= MOD;
			}
			for(int k = 1; k <= k2; k++){
				(dp[i][j + 1][1][k + 1] += dp[i][j][1][k]) %= MOD;
				(dp[i + 1][j][0][1] += dp[i][j][1][k]) %= MOD;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= k1; i++){
		ans += dp[n1][n2][0][i];
		ans %= MOD;
	}
	for(int i = 1; i <= k2; i++){
		ans += dp[n1][n2][1][i];
		ans %= MOD;
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
