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

struct DSU{
	int S;
	struct node{
		int parent; ll sum;
	};
	vector<node> dsu;
	DSU(int n){
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	void reset(int n){
		dsu.clear();
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 1;
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
	ll getsum(int u){
		return dsu[root(u)].sum;
	}
};

int n, m;
string s[1005], s1[1005];
int cc = 0;
int vis[1005][1005], comp[1005][1005];

void dfs(int i, int j){
	if(vis[i][j]) return;
	vis[i][j] = 1;
	comp[i][j] = cc;
	if((i + 1) < n && s1[i][j] != 'C') dfs(i + 1, j);
	if((j + 1) < m && s[i][j] != 'C') dfs(i, j + 1);
	if(i > 0 && s1[i - 1][j] != 'C') dfs(i - 1, j);
	if(j > 0 && s[i][j - 1] != 'C') dfs(i, j - 1);
}

char ver[1005][1005], hor[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	int c = 0;
	rep(i, n) cin >> s[i];
	rep(i, n) rep(j, m - 1) c += (s[i][j] == 'C');
	rep(i, n - 1) cin >> s1[i];
	rep(i, n - 1) rep(j, m) c += (s1[i][j] == 'C');
	//(1, 0) to (1, 1) we check that s[1][0] is a C
	//(1, 1) to (2, 1) we check s[1][1] is a C
	rep(i, n) rep(j, m) if(!vis[i][j]){
		cc++;
		dfs(i, j);
	}
	int req = (m - 1) * (n - 1);
	cout << req << " " << c - (cc - 1) << endl;
	DSU dsu(cc + 1);
	rep(i, n) rep(j, m - 1) ver[i][j] = '.';
	rep(i, n - 1) rep(j, m) hor[i][j] = '.';
	rep(i, n) rep(j, m){
		if((i + 1) < n && s1[i][j] == 'C') hor[i][j] = 'Z';
		if((j + 1) < m && s[i][j] == 'C') ver[i][j] = 'Z';
		if(i > 0 && s1[i - 1][j] == 'C') hor[i - 1][j] = 'Z';
		if(j > 0 && s[i][j - 1] == 'C') ver[i][j - 1] = 'Z';
	}
	rep(i, n) rep(j, m){
		if((i + 1) < n && !dsu.sameset(comp[i][j], comp[i + 1][j])){
			dsu.merge(comp[i][j], comp[i + 1][j]);
			//mark it in the appropriate answer
			hor[i][j] = '.';
		}
		if((j + 1) < m && !dsu.sameset(comp[i][j], comp[i][j + 1])){
			dsu.merge(comp[i][j], comp[i][j + 1]);
			ver[i][j] = '.';
		}
		if(i > 0 && !dsu.sameset(comp[i][j], comp[i - 1][j])){
			dsu.merge(comp[i][j], comp[i - 1][j]);
			hor[i - 1][j] = '.';
		}
		if(j > 0 && !dsu.sameset(comp[i][j], comp[i][j - 1])){
			dsu.merge(comp[i][j], comp[i][j - 1]);
			ver[i][j - 1] = '.';
		}
	}
	int cnt = 0;
	rep(i, n) rep(j, m - 1) cnt += (ver[i][j] == 'Z');
	rep(i, n - 1) rep(j, m) cnt += (hor[i][j] == 'Z');
	rep(i, n - 1) rep(j, m - 1){
		if(hor[i][j + 1] != 'Z' && hor[i][j] != 'Z' && ver[i][j] != 'Z' && ver[i + 1][j] != 'Z'){
			ver[i][j] = 'Z';
			cnt++;
		}
	}	
	rep(i, n - 1) rep(j, m - 1){
		if(hor[i][j] != 'Z' && ver[i][j] != 'Z' && ver[i + 1][j] != 'Z'){
			if(cnt == req) goto stop;
			hor[i][j] = 'Z';
			cnt++;
		}
	}	
	rep(i, n - 1) rep(j, m - 1){
		if(hor[i][j + 1] != 'Z' && hor[i][j] != 'Z' && ver[i][j] != 'Z'){
			if(cnt == req) goto stop;
			ver[i][j] = 'Z';
			cnt++;
		}
	}	
stop:;
	//assert(!(cnt < req));
	rep(i, n){
		rep(j, m - 1) cout << ver[i][j];
		cout << endl;
	}
	rep(i, n - 1){
		rep(j, m) cout << hor[i][j];
		cout << endl;
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
