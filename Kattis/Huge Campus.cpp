#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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

int n, k;
int dp[2][35][35];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	vector<pi> ev;
	rep(i, n){
		int a, b;
		cin >> a >> b;
		a--, b--;
		ev.pb({33, a});
		ev.pb({a, b});
		ev.pb({b, 33});
	}
	string s = "";
	rep(i, n){
		string s1;
		cin >> s1;
		s += s1;
	}
	rep(i, 2) rep(j, 35) rep(k, 35) dp[i][j][k] = 1e9;
	dp[1][33][33] = 0;
	repn(i, 1, 3 * n + 1){
		int cur = i & 1, pr = 1 - cur;
		int u = ev[i - 1].fi, v = ev[i - 1].se;
		if(s[i - 1] == 'R'){
			rep(j, 35) rep(k, 35) if(j == u || k == u){
				int cr = dp[cur][j][k];
				if(j == u) dp[pr][v][k] = min(dp[pr][v][k], cr + 1);
				if(k == u) dp[pr][j][v] = min(dp[pr][j][v], cr + 1);
				if(j == u && k == u) dp[pr][v][v] = min(dp[pr][v][v], cr + 1);
			}
		}
		else{
			rep(j, 35) rep(k, 35){
				int cr = dp[cur][j][k];
				if(j == u) dp[pr][v][k] = min(dp[pr][v][k], cr + 1);
				if(k == u) dp[pr][j][v] = min(dp[pr][j][v], cr + 1);
				if(j == u && k == u) dp[pr][v][v] = min(dp[pr][v][v], cr + 1);
				dp[pr][j][k] = min(dp[pr][j][k], cr);
			}
		}
		rep(j, 35) rep(k, 35) dp[cur][j][k] = 1e9;
	}
	int ind = 1 - ((3 * n) & 1);
	int mn = 1e9;
	rep(j, 35) rep(k, 35) mn = min(mn, dp[ind][j][k]);
	cout << mn << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
