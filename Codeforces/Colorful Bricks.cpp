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

const int MOD = 998244353;
ll dp[2005][2004];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;	
	dp[1][0] = m;
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= k; j++){
			(dp[i + 1][j] += dp[i][j]) %= MOD;
			(dp[i + 1][j + 1] = dp[i][j] * (m - 1)) %= MOD;
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
