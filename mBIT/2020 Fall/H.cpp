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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, k;
string s[mxN];
vector<pi> ed[mxN];

struct DSU{
	int S;
	struct node{
		int parent; int sum;
	};
	vector<node> dsu;
	DSU(int n){
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 0;
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
		dsu[v].parent = u;
		dsu[u].sum += dsu[v].sum;
	}
	bool sameset(int u, int v){
		if(root(u) == root(v)) return true;
		return false;
	}	
	int getsum(int u){
		return dsu[root(u)].sum;
	}
};

DSU dsu(mxN);
int d[mxN], r[mxN], d1[mxN];
int bst[mxN][2];
int vis[mxN];

int f(int i, int j){
	return i * m + j;
}

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

void dfs(int i, int j){
	vis[f(i, j)] = 1;
	rep(k, 4){
		int x = i + dx[k], y = j + dy[k];
		if(valid(x, y) && !vis[f(x, y)] && s[x][y] == '.'){
			dsu.merge(f(i, j), f(x, y));
			dfs(x, y);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, n) cin >> s[i];
	rep(i, k){
		int x, y;
		cin >> x >> y;
		x--, y--;
		dsu.dsu[dsu.root(f(x, y))].sum = 1;
		r[f(x, y)] = 1;
	}
	rep(i, n) rep(j, m) if(s[i][j] == '.' && !vis[f(i, j)]){
		dfs(i, j);
	}
	set<array<int, 3>> q;
	rep(i, mxN) d[i] = 1e9;
	rep(i, n){
		d[f(i, 0)] = (s[i][0] == '#');
		q.insert({d[f(i, 0)], i, 0});
		d[f(i, m - 1)] = (s[i][m - 1] == '#');
		q.insert({d[f(i, m - 1)], i, m - 1});
	}
	rep(j, m){
		d[f(0, j)] = (s[0][j] == '#');
		q.insert({d[f(0, j)], 0, j});
		d[f(n - 1, j)] = (s[n - 1][j] == '#');
		q.insert({d[f(n - 1, j)], n - 1, j});
	}
	while(!q.empty()){
		array<int, 3> cur = *q.begin();
		q.erase(q.begin());
		rep(i, 4){
			int x = cur[1] + dx[i], y = cur[2] + dy[i];
			if(valid(x, y)){
				int cst = (s[x][y] == '#');
				if(d[f(x, y)] > (cst + cur[0])){
					q.erase({d[f(x, y)], x, y});
					d[f(x, y)] = cst + cur[0];
					q.insert({d[f(x, y)], x, y});
				}
			}
		}
	}
	/*
	rep(i, n){
		rep(j, m) cout << d[f(i, j)] << " ";
		cout << endl;
	}
	*/
	int ans = 1e9;
	rep(i, n) rep(j, m) if(dsu.getsum(f(i, j)) > 1) ans = min(ans, d[f(i, j)]);
	vector<pi> pr;
	vi pos;
	rep(i, n) rep(j, m){
		if(dsu.getsum(f(i, j)) == 1 && r[f(i, j)]){
			pr.pb({i, j});
			pos.pb(d[f(i, j)]);
		}
	}
	sort(all(pos));
	if(pos.size() > 1) ans = min(ans, pos[0] + pos[1]);
	rep(i, mxN) rep(j, 2) bst[i][j] = 1e9;
	rep(i, pr.size()){
		set<array<int, 3>> q1;
		memset(d1, 0x3f3f3f3f, sizeof(d1));
		d1[f(pr[i].fi, pr[i].se)] = 0;
		q1.insert({0, pr[i].fi, pr[i].se});
		while(!q1.empty()){
			array<int, 3> cur = *q1.begin();
			q1.erase(q1.begin());
			int nd = f(cur[1], cur[2]);
			if(cur[0] >= bst[nd][1]) continue; 
			if(cur[0] < bst[nd][0]){
				bst[nd][1] = bst[nd][0];
				bst[nd][0] = cur[0];
			}
			else if(cur[0] < bst[nd][1]) bst[nd][1] = cur[0];
			rep(i, 4){
				int x = cur[1] + dx[i], y = cur[2] + dy[i];
				if(valid(x, y)){
					int cst = (s[x][y] == '#');
					if(d1[f(x, y)] > (cst + cur[0])){
						q1.erase({d1[f(x, y)], x, y});
						d1[f(x, y)] = cst + cur[0];
						q1.insert({d1[f(x, y)], x, y});
					}
				}
			}
		}
	}
	rep(i, n) rep(j, m){
		ans = min(ans, bst[f(i, j)][0] + bst[f(i, j)][1] + d[f(i, j)] - (s[i][j] == '#' ? 2 : 0));
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
