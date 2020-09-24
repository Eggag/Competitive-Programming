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
const int maxn = 100005;
const int MOD = 1e9 + 7;

int dp[15][maxn];


struct DivFreed2{
	int count(int n, int k){
             	ios_base::sync_with_stdio(false);
	       	cin.tie(0);
		repn(i, 1, k + 1) dp[1][i] = 1;
		repn(i, 2, n + 1){
			ll sum = 0;
			repn(j, 1, k + 1){
				sum += dp[i - 1][j];
				sum %= MOD;
			}
			repn(j, 1, k + 1){
				ll tmp = 0;
				for(int l = 2 * j; l <= k; l += j){
					tmp += dp[i - 1][l];
					tmp %= MOD;
				}	
				dp[i][j] = (sum - tmp + MOD) % MOD;
			}
		}
		int ans = 0;
		repn(i, 1, k + 1) ans = (ans + dp[n][i]) % MOD;
		return ans;
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/              
