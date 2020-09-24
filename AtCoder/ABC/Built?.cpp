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

bool cmp(pair<pair<ll, ll>, int> a, pair<pair<ll, ll>, int> b){
	if(a.fi.fi != b.fi.fi) return a.fi.fi < b.fi.fi;
	else return a.fi.se < b.fi.se;
}

bool cmp1(pair<pair<ll, ll>, int> a, pair<pair<ll, ll>, int> b){
	if(a.fi.se != b.fi.se) return a.fi.se < b.fi.se;
	else return a.fi.fi < b.fi.fi;
}

ll x[100005], y[100005];

ll cost(pi cur){
	return min(abs(x[cur.fi] - x[cur.se]), abs(y[cur.fi] - y[cur.se]));
}

bool cmp2(pi a, pi b){
	return cost(a) < cost(b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<pair<ll, ll>, int>> p(n);
	rep(i, n){
		cin >> p[i].fi.fi >> p[i].fi.se, p[i].se = i;
		x[i] = p[i].fi.fi;
		y[i] = p[i].fi.se;
	}
	sort(all(p), cmp);
	vector<pi> edges;
	repn(i, 1, n) edges.pb(mp(p[i].se, p[i - 1].se));
	sort(all(p), cmp1);
	repn(i, 1, n) edges.pb(mp(p[i].se, p[i - 1].se));
	sort(all(edges), cmp2);
	DSU dsu(n);
	ll minCost = 0;
	for(pi e : edges) if(!dsu.sameset(e.fi, e.se)){
		dsu.merge(e.fi, e.se);
		minCost += cost(e);
	}
	cout << minCost << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
