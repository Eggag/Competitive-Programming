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
} dsuB(mxN), dsuR(mxN);

int n;
int a, b;
vi g[mxN], g1[mxN]; //g is blue, g1 is red

void end(int f){
	if(!f) cout << "Magenta" << endl;
	else if(f == 1) cout << "Paula" << endl;
	else cout << "Marin" << endl;
	exit(0);
}

int tmF[mxN], dist[mxN];
int vis[mxN], vis1[mxN];
set<int> aset, bset;
int d1 = -1, d2 = -1;

void dfs(int cur, int prev, int d){
	vis[cur] = 1;
	if(bset.find(cur) != bset.end()) d1 = d;
	for(int x : g[cur]) if(x != prev && !vis[x]) dfs(x, cur, d + 1);
}

void dfs1(int cur, int prev, int d){
	vis1[cur] = 1;
	if(aset.find(cur) != aset.end()) d2 = d;
	for(int x : g1[cur]) if(x != prev && !vis1[x]) dfs1(x, cur, d + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	cin >> a >> b;
	a--, b--;
	rep(i, n - 1){
		int a, b;
		string s;
		cin >> a >> b >> s;
		a--, b--;
		if(s[0] == 'p' || s[0] == 'm'){
			g[a].pb(b);
			g[b].pb(a);
		}
		if(s[0] == 'c' || s[0] == 'm'){
			g1[a].pb(b);
			g1[b].pb(a);
		}
	}
	if(!g[a].size() || ((int)g[a].size() == 1 && g[a][0] == b)) end(2);
	if(!g1[b].size()) end(1);
	for(int x : g[a]) aset.insert(x);
	for(int x : g1[a]) aset.insert(x);
	for(int x : g[b]) bset.insert(x);
	for(int x : g1[b]) bset.insert(x);
	dfs(a, -1, 0);
	dfs1(b, -1, 0);
	rep(i, n) if(!vis1[i]){
		for(int x : g[i]) if(!vis1[x]) dsuB.merge(i, x);
	}
	rep(i, n) if(!vis[i]){
		for(int x : g1[i]) if(!vis[x]) dsuR.merge(i, x);
	}
	if(dsuB.getsum(a) > 1 && dsuR.getsum(b) > 1) end(0);
	memset(tmF, 0, sizeof(tmF));
	set<pair<int, pi>> q;
	tmF[a] = 1;
	tmF[b] = 2;
	q.insert(mp(0, mp(a, 1)));
	q.insert(mp(1, mp(b, 2)));
	rep(i, n) dist[i] = 1e9;
	dist[a] = 0, dist[b] = 1;
	while(!q.empty()){
		pair<int, pi> cur = *q.begin();
		q.erase(q.begin());
		if(cur.se.se == 1){
			for(int x : g[cur.se.fi]) if(!tmF[x] || dist[cur.se.fi] + 2 < dist[x]){
				q.erase(mp(dist[x], mp(x, tmF[x])));		
				tmF[x] = cur.se.se;
				dist[x] = 2 + dist[cur.se.fi];
				q.insert(mp(dist[x], mp(x, tmF[x])));		
			}
		}
		else{
			for(int x : g1[cur.se.fi]) if(!tmF[x] || dist[cur.se.fi] + 2 < dist[x]){
				q.erase(mp(dist[x], mp(x, tmF[x])));
				tmF[x] = cur.se.se;
				dist[x] = 2 + dist[cur.se.fi];
				q.insert(mp(dist[x], mp(x, tmF[x])));		
			}
		}
	}
	int f = 0, f1 = 0;
	rep(i, n) if(dsuB.getsum(i) > 1 && tmF[i] == 1) f = 1;
	rep(i, n) if(dsuR.getsum(i) > 1 && tmF[i] == 2) f1 = 1;
	if(f && f1) end(0); //both can hide
	d1++, d2++;
	if(!f && !f1){
		if(d1 % 2 == 0) end(1);
		else end(2);
	}
	if(!f && f1){
		//second maybe win?
		if(d2 & 1) end(2);
		else end(0);
	}
	if(f && !f1){
		//first maybe win?
		if(d1 % 2 == 0) end(1);
		else end(0);
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
