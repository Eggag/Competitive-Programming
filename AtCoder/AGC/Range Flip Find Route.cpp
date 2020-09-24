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

int dp[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	rep(i, 105) rep(j, 105) dp[i][j] = 1e9;
	dp[0][0] = (s[0][0] == '#');
	rep(i, h) rep(j, w){
		if(!i && !j) continue;
		if(i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (s[i][j] == '#'));
		if(j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (s[i][j] == '#'));
		for(int i1 = i - 1; i1 >= 0; i1--){
			if(s[i1][j] == '#') dp[i][j] = min(dp[i][j], dp[i1][j]);
			else break;
		}
		for(int j1 = j - 1; j1 >= 0; j1--){
			if(s[i][j1] == '#') dp[i][j] = min(dp[i][j], dp[i][j1]);
			else break;
		}
	}
	int ans = dp[h - 1][w - 1];
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
