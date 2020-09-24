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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	reverse(all(s));
	rep(i, n) rep(j, n) dp[i][j] = 1e9;
	rep(i, n) dp[i][i] = 1;
	repn(len, 2, n + 1){
		rep(i, n - len + 1){
			int j = i + len - 1;
			dp[i][j] = min(dp[i][j], dp[i + 1][j] + (s[i] != s[i + 1]));
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + (s[j] != s[j - 1]));
			dp[i][j] = min(dp[i][j], dp[i + 1][j] + (s[i] != s[j]));
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + (s[j] != s[i]));
			if(len > 2){
				dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + (s[i] != s[j] ? 2 : (s[i + 1] == s[j - 1] && s[i] == s[i + 1] ? 0 : 1)));
			}
			repn(k, i + 1, j - 1) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
