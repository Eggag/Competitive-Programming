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
const int mxN = 2005;
const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[mxN][mxN];
int ans[mxN * mxN];
int val[mxN * mxN];
int ed;

struct DSU{
	int S;
	struct node{
		int parent;
		vi color;
		ll sum;
	};
	vector<node> dsu;
	DSU(int n){
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 1;
			tmp.color = {(int)(1e9 + i)}; //no color at first
			dsu.pb(tmp);
		}
	}
	int root(int u){
		if(dsu[u].parent == u) return u;
		dsu[u].parent = root(dsu[u].parent);
		return dsu[u].parent;
	}
	void merge(int u, int v){
		u = root(u); v = root(v);
		if(u == v) return;
		if(getsum(u) < getsum(v)) swap(u, v);
		if(dsu[v].color[0] < 1e9 && dsu[u].color[0] < 1e9 && val[dsu[u].color[0]] == val[dsu[v].color[0]]){
			rep(i, dsu[v].color.size()) dsu[u].color.pb(dsu[v].color[i]);
		}
		if(dsu[v].color[0] < 1e9 && dsu[u].color[0] < 1e9 && val[dsu[u].color[0]] != val[dsu[v].color[0]]){
			if(dsu[v].color[0] < dsu[u].color[0]){
				rep(i, dsu[u].color.size()) ans[dsu[u].color[i]] = max(ed, ans[dsu[u].color[i]]);
			}
			else{
				rep(i, dsu[v].color.size()) ans[dsu[v].color[i]] = max(ed, ans[dsu[v].color[i]]);
			}
		}
		if(dsu[v].color[0] < 1e9 && dsu[u].color[0] >= 1e9) dsu[u].color = dsu[v].color;
		else if(dsu[v].color[0] < 1e9 && dsu[u].color[0] < 1e9 && val[dsu[v].color[0]] > val[dsu[u].color[0]]) dsu[u].color = dsu[v].color;
		dsu[v].parent = u;
		dsu[u].sum += dsu[v].sum;
	}
	bool sameset(int u, int v){
		if(root(u) == root(v)) return true;
		return false;
	}	
	ll getsum(int u){
		return dsu[root(u)].sum;
	}
};

int vis[mxN][mxN];

bool cmp(pair<int, pi> a, pair<int, pi> b){
	return a.fi > b.fi;
}

bool cmp1(pi a, pi b){
	if(a.fi != b.fi) return a.fi > b.fi;
	return a.se > b.se;
}

vector<pi> cur;
int col = 0, bad = 0;

int n, m;

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

void dfs(int x, int y){
	vis[x][y] = 1;
	cur.pb({x, y});
	rep(i, 8){
		int x1 = x + dx[i], y1 = y + dy[i];
		if(valid(x1, y1) && !vis[x1][y1]){
			if(g[x1][y1] == g[x][y]) dfs(x1, y1);
		}
		if(valid(x1, y1) && g[x1][y1] > g[x][y]) bad = 1;
	}
}

int f(int i, int j){
	return (i * m + j);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	map<int, vector<pi>> cnt;
	vector<pair<int, pi>> ord;
	rep(i, n) rep(j, m) cin >> g[i][j], cnt[g[i][j]].pb({i, j}), ord.pb(mp(g[i][j], mp(i, j)));
	sort(all(ord), cmp);
	DSU dsu(n * m);
	rep(i, n * m) if(!vis[ord[i].se.fi][ord[i].se.se]){
		col++;
		cur.clear();
		bad = 0;
		dfs(ord[i].se.fi, ord[i].se.se);
		if(bad) col--;
		else{
			dsu.dsu[dsu.root(f(cur[0].fi, cur[0].se))].color = {col};
			val[col] = g[cur[0].fi][cur[0].se];
			rep(j, cur.size()){
				dsu.merge(f(cur[0].fi, cur[0].se), f(cur[j].fi, cur[j].se));
			}
		}
	}
	rep(i, col + 1) ans[i] = 0;
	for(int i = 1e6; i >= 0; i--) if(cnt[i].size()){
		ed = i;
		for(pi p : cnt[i]){
			rep(k, 8){
				int x = p.fi + dx[k], y = p.se + dy[k];
				int x1 = p.fi, y1 = p.se;
				if(valid(x, y) && valid(x1, y1)){
					if(!dsu.sameset(f(x1, y1), f(x, y)) && g[x][y] >= i && g[x1][y1] >= i){
						dsu.merge(f(x1, y1), f(x, y));
					}
				}
			}
			rep(k, 8) rep(j, 8){
				int x = p.fi + dx[k], y = p.se + dy[k];
				int x1 = p.fi + dx[j], y1 = p.se + dy[j];
				if(valid(x, y) && valid(x1, y1)){
					if(!dsu.sameset(f(x1, y1), f(x, y)) && g[x][y] >= i && g[x1][y1] >= i){
						dsu.merge(f(x1, y1), f(x, y));
					}
				}
			}
		}
	}
	vector<pi> ret;
	repn(i, 1, col + 1) ret.pb({val[i], ans[i]});
	sort(all(ret), cmp1);
	cout << ret.size() << endl;
	rep(i, ret.size()) cout << ret[i].fi << " " << ret[i].se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
