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

vi g[mxN];

int n, l;
vector<int> tin, tout;
int timer;
vector<vector<int>> up;
int d[mxN], dist[mxN];

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

void dfs0(int cur, int lev, int prev = -1){
	d[cur] = 1;
	dist[cur] = lev;
	for(int x : g[cur]) if(x != prev){
		dfs0(x, lev + 1, cur);
		d[cur] += d[x];
	}
}

int deb = 0;

int f(int u, int v){
	int x = lca(u, v);
	if(x != u && x != v && dist[v] == dist[u]){
		int ret = n;
		int cur = v;
		int de = dist[v] - dist[x] - 1;
		rep(i, 25){
			if(de & (1 << i)){
				cur = up[cur][i];
			}
		}
		ret -= d[cur];
		cur = u;
		de = dist[u] - dist[x] - 1;
		rep(i, 25){
			if(de & (1 << i)){
				cur = up[cur][i];
			}
		}
		ret -= d[cur];
		return ret;
	}
	if(u == v) return n;
	//u above v
	if(dist[v] < dist[u]) swap(u, v);
	if((dist[u] & 1) != (dist[v] & 1)) return 0;
	int de = (dist[v] - dist[u]) / 2;
	if(x != u && x != v) de = (dist[u] + dist[v] - 2 * dist[x]) / 2;
	//d is how much we have to go up
	int cur = v;
	rep(i, 25){
		if(de & (1 << i)){
			cur = up[cur][i];
		}
	}
	int ret = d[cur];
	//now we do the same thing but d = d - 1
	int mid = cur;
	cur = v;
	de = dist[v] - dist[mid] - 1;
	rep(i, 25){
		if(de & (1 << i)){
			cur = up[cur][i];
		}
	}
	ret -= d[cur];
	//we might need to do some stuff from the other vertex too
	if(upper(mid, u)){
		cur = u;
		de = dist[u] - dist[mid] - 1;
		if(de >= 0){
			rep(i, 25){
				if(de & (1 << i)){
					cur = up[cur][i];
				}
			}
			ret -= d[cur];
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	if(n == 1e5) deb = 1;
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
	dfs0(0, 0);
	int m;
	cin >> m;
	rep(i, m){
		int u, v;
		cin >> u >> v;
		u--, v--;
		cout << f(u, v) << '\n';
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
