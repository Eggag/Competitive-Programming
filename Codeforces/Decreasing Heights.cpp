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
const int mxN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll g[mxN][mxN];
ll dp[mxN][mxN];

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	vector<ll> pos;
	rep(i, n) rep(j, m){
		ll p = g[i][j] - (i + j);
		if(p <= g[0][0]) pos.pb(p);
	}
	ll mn = 1e18;
	rep(k, pos.size()){
		memset(dp, -1, sizeof(dp));
		dp[0][0] = g[0][0] - pos[k];
		rep(i, n) rep(j, m){
			ll ta = pos[k] + i + j;
			if(g[i][j] < ta) continue;
			if(i && ~dp[i - 1][j]) dp[i][j] = dp[i - 1][j] + (g[i][j] - ta);
			if(j && ~dp[i][j - 1]){
				if(!~dp[i][j]) dp[i][j] = dp[i][j - 1] + (g[i][j] - ta);
				else dp[i][j] = min(dp[i][j], dp[i][j - 1] + (g[i][j] - ta));
			}
		}
		if(~dp[n - 1][m - 1]) mn = min(mn, dp[n - 1][m - 1]);
	}
	cout << mn << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
