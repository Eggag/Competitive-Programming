#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define inf 0x3f3f3f3f
const int mxN = 2e5 + 5;

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
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vi c(n);
	vector<array<int, 4>> p(n);
	DSU dsu(1 + (n * 2));
	rep(i, n){
		cin >> c[i];
		rep(j, 4) cin >> p[i][j];
		dsu.merge(p[i][0], p[i][1]);
		dsu.merge(p[i][2], p[i][3]);
	}
	int cost = 0;
	vector<pair<int, pi>> ed;
	rep(i, n) if(dsu.root(p[i][0]) != dsu.root(p[i][2])){
		ed.pb(mp(c[i], mp(dsu.root(p[i][0]), dsu.root(p[i][2]))));
	}
	sort(all(ed));
	DSU dsu1(1 + (n * 2));
	rep(i, ed.size()) if(!dsu1.sameset(ed[i].se.fi, ed[i].se.se)){
		cost += ed[i].fi;
		dsu1.merge(ed[i].se.fi, ed[i].se.se);
	}
	cout << cost << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
