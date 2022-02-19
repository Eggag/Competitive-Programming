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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
int d[mxN];
vi g[mxN];
vector<pi> tmp[mxN];
vector<vector<pi>> owo;
ll num[mxN];

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
} dsu(mxN);

bool cmp(vector<pi> a, vector<pi> b){
	int a1 = num[dsu.root(a[0].fi)], b1 = num[dsu.root(b[0].fi)];
	return a1 < b1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	ll sum = 0;
	rep(i, n) cin >> d[i], sum += d[i];
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		dsu.merge(a, b);
	}
	if(sum != 2 * (n - 1)){
		cout << "-1\n";
		return 0;
	}
	rep(i, n) if(d[i] < (int)(g[i].size())){
		cout << "-1\n";
		return 0;
	}
	ll tot = 0;
	rep(i, n) tot += d[i] - (int)(g[i].size());
	if(tot != 2 * (n - m - 1)){
		cout << "-1\n";
		return 0;
	}
	vector<pi> ans;
	rep(i, n) if(d[i] > (int)(g[i].size())){
		tmp[dsu.root(i)].pb(mp(i, d[i] - (int)(g[i].size())));
		num[dsu.root(i)] += d[i] - (int)(g[i].size());
	}
	rep(i, n) if(tmp[i].size()) owo.pb(tmp[i]);
	sort(all(owo), cmp);
	for(int i = (int)(owo.size()) - 1; i >= 0; i--){
		if(!i) break;
		if(!owo[i].size()){
			cout << "-1\n";
			return 0;
		}
		
		int k = (int)(owo[i].size());
		int u = owo[i][k - 1].fi;
		owo[i][k - 1].se--;
		if(!owo[i][k - 1].se) owo[i].pop_back();

		int k1 = (int)(owo[i - 1].size());
		int v = owo[i - 1][k1 - 1].fi;
		owo[i - 1][k1 - 1].se--;
		if(!owo[i - 1][k1 - 1].se) owo[i - 1].pop_back();

		ans.pb(mp(u, v));
		dsu.merge(u, v);

		if(owo[i].size() > owo[i - 1].size()) swap(owo[i], owo[i - 1]);
		for(pi x : owo[i]) owo[i - 1].pb(x);
		owo[i].clear();
	}
	int cnt = 0;
	rep(i, n) if(dsu.root(i) == i) cnt++;
	if(cnt == 1){
		vi fufu;
		rep(i, owo.size()) rep(j, owo[i].size()){
			rep(k, owo[i][j].se / 2) ans.pb(mp(owo[i][j].fi, owo[i][j].fi));
			if(owo[i][j].se & 1) fufu.pb(owo[i][j].fi);
		}
		if((int)(fufu.size()) & 1){
			cout << "-1\n";
			return 0;
		}
		rep(i, (int)(fufu.size()) / 2) ans.pb(mp(fufu[i], fufu[(int)(fufu.size()) - i - 1]));
		for(pi y : ans) cout << y.fi + 1 << " " << y.se + 1 << '\n';
	}
	else cout << "-1\n";
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
