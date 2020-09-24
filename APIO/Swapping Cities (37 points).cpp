#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "swap.h"
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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct DSUrb {
	vi e; void init(int n) { e = vi(n,-1); }
	int get(int x) { return e[x] < 0 ? x : get(e[x]); }
	bool sameset(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	vector<array<int,4>> mod;
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y);
		if (x == y) { mod.pb({-1,-1,-1,-1}); return 0; }
		if (e[x] > e[y]) swap(x,y);
		mod.pb({x,y,e[x],e[y]});
		e[x] += e[y]; e[y] = x; return 1;
	}
	void rollback() {
		auto a = mod.back(); mod.pop_back();
		if (a[0] != -1) e[a[0]] = a[2], e[a[1]] = a[3];
	}
};

int n, m, x, y;
int u[mxN], v[mxN], w[mxN];
int deg[mxN], vis[mxN];
vi g[mxN];

void init(int N, int M, vector<int> U, vector<int> V, vector<int> W){
	n = N, m = M;
	rep(i, m) u[i] = U[i];
	rep(i, m) v[i] = V[i];
	rep(i, m) w[i] = W[i];
}

bool check(int ge){
	rep(i, n) g[i].clear(), deg[i] = 0;
	DSUrb dsu;
	dsu.init(n);
	rep(i, m){
		if(w[i] <= ge){
			dsu.unite(u[i], v[i]);
			g[u[i]].pb(v[i]);
			g[v[i]].pb(u[i]);
			deg[u[i]]++;
			deg[v[i]]++;
		}
	}
	if(!dsu.sameset(x, y)) return 0;
	rep(i, n){
		if(i != x && i != y){
			if(deg[i] > 2 && dsu.sameset(x, i) && dsu.sameset(y, i)) return 1;
		}
	}
	DSUrb dsu1;
	dsu1.init(n);
	rep(i, m){
		if(w[i] <= ge && u[i] != x && v[i] != x){
			dsu1.unite(u[i], v[i]);
		}
	}
	int nm = 0;
	for(int ed : g[x]){
		dsu1.unite(x, ed);
		if(dsu1.sameset(x, y)) nm++;
		dsu1.rollback();
	}
	if(nm > 1) return 1;
	DSUrb dsu2;
	dsu2.init(n);
	rep(i, m){
		if(w[i] <= ge && u[i] != y && v[i] != y){
			dsu2.unite(u[i], v[i]);
		}
	}
	nm = 0;
	for(int ed : g[y]){
		dsu2.unite(y, ed);
		if(dsu2.sameset(x, y)) nm++;
		dsu2.rollback();
	}
	if(nm > 1) return 1;
	return 0;
}

int getMinimumFuelCapacity(int X, int Y){
	x = X, y = Y;
	int l = 0, r = 1e9 + 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(!check(l)) return -1;
	return l;
}
