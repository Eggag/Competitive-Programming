#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'
const int MOD = 1e9 + 7;

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[5005][5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	char p = 'c';
	dp[0][0] = 1;
	repn(i, 1, n + 1){
		char c;
		cin >> c;
		if(p == 'f'){
			rep(j, i + 1) dp[i][j + 1] = dp[i - 1][j];
		}
		else{
			rep(j, i + 1) dp[i][j] = dp[i - 1][j];
			for(int j = i; j >= 1; j--){
				dp[i][j - 1] = (dp[i][j - 1] + dp[i][j]) % MOD;
			}
		}
		p = c;
	}
	ll ans = 0;
	rep(i, n + 1) ans = (ans + dp[n][i]) % MOD;
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
