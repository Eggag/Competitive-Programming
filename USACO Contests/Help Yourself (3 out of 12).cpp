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

bool intersect(int a, int b, int c, int d){
	return ((a >= c && a <= d) || (b >= c && b <= d));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	sort(all(p));
	int ans = 0;
	repn(i, 1, (1 << n)){
		vector<pi> cur;
		rep(j, n) if(i & (1 << j)) cur.pb(p[j]);
		DSU dsu((int)cur.size());
		rep(j, cur.size()) rep(k, cur.size()) if(intersect(cur[j].fi, cur[j].se, cur[k].fi, cur[k].se)) dsu.merge(j, k);
		rep(j, cur.size()) if(dsu.root(j) == j) ans++;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
