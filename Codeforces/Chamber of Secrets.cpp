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

int dp[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	rep(i, 1005) rep(j, 1005) dp[i][j] = 1e9;
	vi mn(m, 1e9); //the minimum cost to get to that col
	rep(j, m) if(s[0][j] == '#') dp[0][j] = 0, mn[j] = min(mn[j], 0);
	rep(_, 300){
		repn(i, 1, n){
			int mnC = 1e9;
			rep(j, m) if(s[i][j] == '#'){
				dp[i][j] = min(dp[i][j], mn[j] + 1);
				mnC = min(mnC, dp[i][j]);
				mn[j] = min(mn[j], dp[i][j]);
			}
			rep(j, m) if(s[i][j] == '#'){
				dp[i][j] = min(dp[i][j], mnC + 1);
				mn[j] = min(mn[j], dp[i][j]);
			}
		}
		int ans = 1e9;
		rep(j, m) ans = min(ans, dp[n - 1][j] + 1);
		if(ans != 1e9){
			cout << ans << endl;
			return 0;
		}
	}
	int ans = 1e9;
	rep(j, m) ans = min(ans, dp[n - 1][j] + 1);
	if(ans >= 1e8) ans = -1;
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
