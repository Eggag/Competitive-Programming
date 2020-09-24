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
const int MOD = 1e9 + 7;

int dp[2005][2005];

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	repn(i, 1, n + 1) dp[1][i] = 1;
	repn(i, 2, k + 1){
		repn(j, 1, n + 1){
			for(int p = j; p <= n; p += j){
				dp[i][p] = (dp[i][p] + dp[i - 1][j]) % MOD;
			}
		}
	}
	int ans = 0;
	repn(i, 1, n + 1){
		ans = (ans + dp[k][i]) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
