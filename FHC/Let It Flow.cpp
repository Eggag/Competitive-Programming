#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
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

void solve(){
	int n;
	cin >> n;
	string s[3];
	rep(i, 3) cin >> s[i];
	ll dp[n + 1][3];
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[0][2] = 0;
	repn(i, 1, n + 1){
		rep(j, 3) dp[i][j] = 0;
		if(s[0][i - 1] == '.' && s[1][i - 1] == '.'){
			dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
			dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
		}
		if(s[1][i - 1] == '.' && s[2][i - 1] == '.'){
			dp[i][1] = (dp[i][1] + dp[i - 1][2]) % MOD;
			dp[i][2] = (dp[i][2] + dp[i - 1][1]) % MOD;
		}
	}
	cout << dp[n][2] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("let_it_flow.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
