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

string s[100];

int dp[105][105][105]; //[i][j][level]

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int r, c, m;
	cin >> r >> c >> m;
	rep(i, r) cin >> s[i];
	string moves;
	cin >> moves;
	rep(i, r) rep(j, c) if(s[i][j] == '.') dp[i][j][0] = 1;
	repn(level, 1, m + 1) rep(i, r) rep(j, c) if(s[i][j] == '.' && dp[i][j][level - 1]){
		//update from it
		char cur = moves[level - 1];
		if(cur == '?' || cur == 'W') if(j > 0 && s[i][j - 1] == '.') dp[i][j - 1][level] |= dp[i][j][level - 1];
		if(cur == '?' || cur == 'E') if(j < (c - 1) && s[i][j + 1] == '.') dp[i][j + 1][level] |= dp[i][j][level - 1];
		if(cur == '?' || cur == 'N') if(i > 0 && s[i - 1][j] == '.') dp[i - 1][j][level] |= dp[i][j][level - 1];
		if(cur == '?' || cur == 'S') if(i < (r - 1) && s[i + 1][j] == '.') dp[i + 1][j][level] |= dp[i][j][level - 1];
	}
	int ans = 0;
	rep(i, r) rep(j, c) ans += dp[i][j][m];
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
