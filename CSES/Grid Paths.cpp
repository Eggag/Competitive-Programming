#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int MOD = 1e9 + 7;
 
int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
char g[1005][1005];
ll dp[1005][1005];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) rep(j, n) cin >> g[i][j];
	rep(i, 1005) rep(j, 1005) dp[i][j] = 0;
	dp[0][0] = 1;
	if(g[0][0] == '*'){
		cout << 0 << endl;
		return 0;
	}
	rep(i, n) rep(j, n){
		if(!i && !j) continue;
		if(i) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
		if(j) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
		if(g[i][j] == '*') dp[i][j] = 0;
	}
	cout << dp[n - 1][n - 1] % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
