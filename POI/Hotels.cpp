#include <bits/stdc++.h>
using namespace std;
#define int short
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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int n, l;
vi tin, tout;
int timer = 0;
vector<vi> up;

void dfs(int v, int p = 0){
	tin[v] = timer++;
	up[v][0] = p;
	repn(i, 1, l + 1) up[v][i] = up[up[v][i - 1]][i - 1];
	rep(i, g[v].size()){
		int to = g[v][i];
		if(to != p) dfs(to, v);
	}
	tout[v] = timer++;
}

bool upper(int a, int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	for(int i = l; i >= 0; i--) if(!upper(up[a][i], b)) a = up[a][i];
	return up[a][0];
}

int d[mxN];
int dist[mxN][mxN];

void dfs1(int cur, int prev, int de){
	d[cur] = de;
	dist[cur][0] = 1;
	for(int x : g[cur]) if(x != prev){
		dfs1(x, cur, de + 1);
		repn(i, 1, mxN) dist[cur][i] += dist[x][i - 1];
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	tin.resize(n);
	tout.resize(n);
	up.resize(n);
	l = 1;
	while((1 << l) <= n) l++;
	rep(i, n) up[i].resize(l + 1);
	dfs(0);
	dfs1(0, -1, 0);
	ll ans = 0LL, ans1 = 0LL;
	rep(i, n) repn(j, i + 1, n){
		int k = lca(i, j);
		int dst = (d[j] + d[i]) - (2 * d[k]);
		if(dst & 1) continue;
		int cur = dst / 2;
		int nd = (d[i] > d[j] ? i : j), nd1 = nd;
		rep(m, 15) if(cur & (1 << m)) nd = up[nd][m];
		cur--;
		rep(m, 15) if(cur & (1 << m)) nd1 = up[nd1][m];
		int nw = dist[nd][dst / 2] - dist[nd1][(dst / 2) - 1];
		if(d[i] == d[j]){
			nd1 = i;
			rep(m, 15) if(cur & (1 << m)) nd1 = up[nd1][m];
			nw -= dist[nd1][cur];
			ans1 += nw;
		}
		else ans += nw;
	}
	cout << ans / 2 + ans1 / 3 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
