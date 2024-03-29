#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
vector<pi> g[mxN];
ll dp[mxN][2];

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return a.fi - a.se > b.fi - b.se;
}

void dfs(int u, int prev){
	vector<pair<ll, ll>> p;
	for(pi v : g[u]) if(v.fi != prev){
		dfs(v.fi, u);
		p.pb(mp(dp[v.fi][1] + (ll)(v.se), dp[v.fi][0]));
	}
	sort(all(p), cmp);
	rep(i, p.size()){
		if(p[i].se >= p[i].fi){
			dp[u][0] += p[i].se;
			dp[u][1] += p[i].se;
		}
		else{
			if(i < k) dp[u][0] += p[i].fi;
			else dp[u][0] += p[i].se;
			if(i < (k - 1)) dp[u][1] += p[i].fi;
			else dp[u][1] += p[i].se;
		}
	}
}

void solve(){
	cin >> n >> k;
	rep(i, n) g[i].clear();
	rep(i, n - 1){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	rep(i, n) rep(j, 2) dp[i][j] = 0LL;
	dfs(0, -1);
	cout << dp[0][0] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
