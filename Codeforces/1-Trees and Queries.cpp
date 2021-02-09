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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
vi g[mxN];
vector<vi> up;
int st[mxN], fin[mxN], d[mxN];
int num = 0, l = 1;

void dfs(int cur, int prev = 0, int di = 0){
	st[cur] = num++;
	d[cur] = di;
	up[cur][0] = prev;
	repn(i, 1, l + 1) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for(int x : g[cur]) if(x != prev) dfs(x, cur, di + 1);
	fin[cur] = num++;
}

bool upper(int a, int b){
	return st[a] <= st[b] && fin[a] >= fin[b];
}

int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	for(int i = l; i >= 0; i--) if(!upper(up[a][i], b)) a = up[a][i];
	return up[a][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n - 1){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	up.resize(n + 1);
	while((1 << l) <= n) l++;
	rep(i, n) up[i].resize(l + 1);
	dfs(0);
	int q;
	cin >> q;
	while(q--){
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		x--, y--, a--, b--;
		int f = 0;
		int c = lca(a, b);
		int dist = d[a] + d[b] - (2 * d[c]);
		if(dist <= k && (k - dist) % 2 == 0) f = 1;
		c = lca(a, x);
		dist = d[a] + d[x] - (2 * d[c]) + 1;
		int c1 = lca(y, b);
		dist +=  d[b] + d[y] - (2 * d[c1]);
		if(dist <= k && (k - dist) % 2 == 0) f = 1;
		swap(x, y);
		c = lca(a, x);
		dist = d[a] + d[x] - (2 * d[c]) + 1;
		c1 = lca(y, b);
		dist +=  d[b] + d[y] - (2 * d[c1]);
		if(dist <= k && (k - dist) % 2 == 0) f = 1;
		cout << (f ? "YES" : "NO") << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
