#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

bool cmp(pair<pi, int> a, pair<pi, int> b){
	if(a.fi.fi != b.fi.fi) return a.fi.fi < b.fi.fi;
	return a.fi.se < b.fi.se;
}

bool cmp1(pair<pi, int> a, pair<pi, int> b){
	if(a.fi.se != b.fi.se) return a.fi.se < b.fi.se;
	return a.fi.fi < b.fi.fi;
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<pair<pi, int>> p(n);
	DSU dsu(n);
	vector<pi> f;
	rep(i, n){
		cin >> p[i].fi.fi >> p[i].fi.se, p[i].se = i;
		int t;
		cin >> t;
		f.pb(mp(t, i));
	}
	sort(all(p), cmp);
	repn(i, 1, n) if(p[i].fi.fi == p[i - 1].fi.fi){
		if(abs(p[i].fi.se - p[i - 1].fi.se) <= k) dsu.merge(p[i].se, p[i - 1].se);
	}
	sort(all(p), cmp1);
	repn(i, 1, n) if(p[i].fi.se == p[i - 1].fi.se){
		if(abs(p[i].fi.fi - p[i - 1].fi.fi) <= k) dsu.merge(p[i].se, p[i - 1].se);
	}
	sort(all(f));
	vi vis(n, 0);
	int uwu = 0;
	rep(i, n) if(dsu.root(i) == i) uwu++;
	int ans = uwu;
	rep(i, n){
		if(!vis[dsu.root(f[i].se)]){
			vis[dsu.root(f[i].se)] = 1;
			if(f[i].fi < uwu - 1) uwu--;
		}
		ans = min(ans, uwu);
	}
	cout << ans - 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
