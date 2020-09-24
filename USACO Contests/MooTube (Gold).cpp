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
};

bool cmp(pair<int, pi> a, pair<int, pi> b){
	return a.fi > b.fi;
}

bool cmp1(pair<pi, int> a, pair<pi, int> b){
	return a.fi.fi > b.fi.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<pair<int, pi>> ed;
	rep(i, n - 1){
		int a, b, c;
		cin >> a >> b >> c;
		ed.pb(mp(c, mp(a, b)));
	}
	sort(all(ed), cmp);
	vector<pair<pi, int>> k(q);
	rep(i, q) cin >> k[i].fi.fi >> k[i].fi.se, k[i].se = i;
	vi ans(q, 0);
	int ind = 0;
	sort(all(k), cmp1);
	DSU dsu(n);
	rep(i, q){
		while(ed[ind].fi >= k[i].fi.fi){
			dsu.merge(ed[ind].se.fi, ed[ind].se.se);
			ind++;
		}
		ans[k[i].se] = dsu.getsum(k[i].fi.se) - 1;
	}
	rep(i, q) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
