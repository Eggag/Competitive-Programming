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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll dp[mxN];
int d[mxN];
vector<pi> g[mxN];
ll ans = 0LL;

void dfs(int cur, int prev){
	d[cur] = 1;
	for(pi x : g[cur]) if(x.fi != prev){
		dfs(x.fi, cur);
		if(d[x.fi] % 2 == 0) dp[cur] += dp[x.fi];
		else dp[cur] += dp[x.fi] + x.se;
		ans += (1LL * x.se * min(d[x.fi], n - d[x.fi]));
		d[cur] += d[x.fi];
	}
}

void solve(){
	cin >> n;
	n *= 2;
	rep(i, n) g[i].clear();
	memset(dp, 0, sizeof(dp));
	ans = 0LL;
	rep(i, n - 1){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	dfs(0, -1);
	cout << dp[0] << " " << ans << '\n';
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
