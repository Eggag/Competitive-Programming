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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN], p[2];
int vis[mxN];

void dfs(int cur, int prev, int dep = 0){
	p[dep].pb(cur);
	for(int x : g[cur]) if(x != prev) dfs(x, cur, dep ^ 1);
}

void solve(){
	int n;
	cin >> n;
	rep(i, n + 1) vis[i] = 0, g[i].clear();
	rep(i, 2) p[i].clear();
	rep(i, n - 1){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0, -1);
	if(p[0].size() > p[1].size()) swap(p[0], p[1]);
	int m = (int)(p[0].size()), uwu = 0, owo = 0;
	vi ans(n, -1);
	rep(i, 25){
		int st = 1 << i;
		if(m & (1 << i)) while(st <= n && st < (1 << (i + 1))) ans[p[0][uwu++]] = st++;
		else while(st <= n && st < (1 << (i + 1))) ans[p[1][owo++]] = st++;
	}
	rep(i, n) cout << ans[i] << ' ';
	cout << '\n';
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
