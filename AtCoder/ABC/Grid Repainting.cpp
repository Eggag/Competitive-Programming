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

int dp[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	int tot = 0;
	rep(i, h) rep(j, w) if(s[i][j] == '.') tot++;
	rep(i, 55) rep(j, 55) dp[i][j] = 1e9;
	dp[0][0] = 0;
	rep(k, 1000) rep(i, h) rep(j, w) if(s[i][j] == '.'){
		if(!i && !j) continue;
		if(i > 0) dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
		if(j > 0) dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
		if(i < (h - 1)) dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
		if(j < (w - 1)) dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
	}
	if(dp[h - 1][w - 1] == 1e9) cout << -1 << endl;
	else cout << tot - dp[h - 1][w - 1] - 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
