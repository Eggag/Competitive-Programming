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

int n;
ll c[5][100005];
int deg[100005], col[100005];
vi g[100005];
pair<ll, vi> dp[3][100005];
pair<int, pi> last;
vi vis;

void dfs(int cur, int prev){
	dp[0][cur].fi = c[0][cur];
	dp[1][cur].fi = c[1][cur];
	dp[2][cur].fi = c[2][cur];
	if(prev != -1){
		dp[0][cur].fi += min(dp[1][prev].fi, dp[2][prev].fi);
		if(dp[1][prev].fi < dp[2][prev].fi) dp[0][cur].se = dp[1][prev].se;
		else dp[0][cur].se = dp[2][prev].se;
		dp[0][cur].se.pb(1);
		//
		dp[1][cur].fi += min(dp[0][prev].fi, dp[2][prev].fi);
		if(dp[0][prev].fi < dp[2][prev].fi) dp[1][cur].se = dp[0][prev].se;
		else dp[1][cur].se = dp[2][prev].se;
		dp[1][cur].se.pb(2);
		//
		dp[2][cur].fi += min(dp[0][prev].fi, dp[1][prev].fi);
		if(dp[0][prev].fi < dp[1][prev].fi) dp[2][cur].se = dp[0][prev].se;
		else dp[2][cur].se = dp[1][prev].se;
		dp[2][cur].se.pb(3);
	}
	else{
		dp[0][cur].se = {1};
		dp[1][cur].se = {2};
		dp[2][cur].se = {3};
	}
	last = mp(dp[0][cur].fi, mp(dp[1][cur].fi, dp[2][cur].fi));
	vis.pb(cur);
	for(int u : g[cur]) if(u != prev) dfs(u, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	memset(deg, 0, sizeof(deg));
	rep(i, 3) rep(j, n) cin >> c[i][j];
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		deg[a]++, deg[b]++;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i, n) if(deg[i] == 3){
		cout << -1 << endl;
		return 0;
	}
	dfs(0, -1);
	ll ans = min({last.fi, last.se.fi, last.se.se});
	cout << ans << endl;
	int lastv = vis[vis.size() - 1];
	//rep(i, ((int)dp[0][lastv].se.size())) debug(dp[0][lastv].se[i]);
	//rep(i, ((int)dp[1][lastv].se.size())) debug(dp[0][lastv].se[i]);
	//rep(i, ((int)dp[2][lastv].se.size())) debug(dp[0][lastv].se[i]);
	if(last.fi == ans){
		for(int i = (int)(dp[0][lastv].se.size()) - 1; i >= 0; i--){
			col[vis[vis.size() - 1]] = dp[0][lastv].se[i];
			vis.pop_back();
		}
		rep(i, n) cout << col[i] << " ";
		cout << endl;
		return 0;
	}
	if(last.se.fi == ans){
		for(int i = (int)(dp[1][lastv].se.size()) - 1; i >= 0; i--){
			col[vis[vis.size() - 1]] = dp[0][lastv].se[i];
			vis.pop_back();
		}
		rep(i, n) cout << col[i] << " ";
		cout << endl;
		return 0;
	}
	if(last.se.se == ans){
		for(int i = (int)(dp[2][lastv].se.size()) - 1; i >= 0; i--){
			col[vis[vis.size() - 1]] = dp[0][lastv].se[i];
			vis.pop_back();
		}
		rep(i, n) cout << col[i] << " ";
		cout << endl;
		return 0;
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
