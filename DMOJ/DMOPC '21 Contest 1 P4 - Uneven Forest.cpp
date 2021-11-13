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
const int mxN = 1e3 + 5;

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

int n, m, k;
vector<array<int, 3>> g[mxN];
map<ll, int> dp[mxN];
vi rt;

void dfs(int cur, int prev, ll mx, int le, int de){
	map<ll, int> ndp[2];
	int nm = 0;
	for(array<int, 3> x : g[cur]) if(x[0] != prev){
		dfs(x[0], cur, mx, x[1], x[2]);
		int cr = nm & 1, pr = 1 - cr;
		if(!nm) ndp[cr] = dp[x[0]];
		else{
			for(pair<ll, int> y : ndp[pr]){
				for(pair<ll, int> z : dp[x[0]]){
					ll bg = y.fi + z.fi;
					if(bg > mx) break;
					bg = max(y.fi, z.fi);
					if(ndp[cr].find(bg) == ndp[cr].end()){
						if(y.se + z.se < (k + 1)) ndp[cr][bg] = y.se + z.se;
					}
					else if(y.se + z.se < (k + 1)){
						ndp[cr][bg] = min(ndp[cr][bg], y.se + z.se);
					}
				}
			}
			ndp[pr].clear();
		}
		nm++;
	}
	if(!nm){
		//take
		if(prev != -1 && le <= mx) dp[cur][le] = 0;
		//no take
		dp[cur][0] = de;
	}
	for(pair<ll, int> x : ndp[1 - (nm & 1)]){
		//take
		if(prev != -1){
			if(x.fi + le <= mx){
				if(dp[cur].find(x.fi + le) == dp[cur].end()){
					if(x.se < (k + 1)) dp[cur][x.fi + le] = x.se;
				}
				else if(x.se < (k + 1)) dp[cur][x.fi + le] = min(dp[cur][x.fi + le], x.se);
			}
		}
		//no take
		if(dp[cur].find(0) == dp[cur].end()){
			if(x.se + de < (k + 1)) dp[cur][0] = x.se + de;
		}
		else if(x.se + de < (k + 1)) dp[cur][0] = min(dp[cur][0], x.se + de);
	}
}

bool check(ll mx){
	rep(i, n) dp[i].clear();
	rep(i, rt.size()) dfs(rt[i], -1, mx, -1, -1);
	ll tot = 0;
	rep(i, rt.size()){
		ll c = 1e18;
		for(pair<ll, int> x : dp[rt[i]]) c = min(c, (ll)x.se);
		tot += c;
		if(tot > k) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	DSU dsu(n);
	rep(i, m){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--;
		g[a].pb(array<int, 3>{b, c, d});
		g[b].pb(array<int, 3>{a, c, d});
		dsu.merge(a, b);
	}
	rep(i, n) if(dsu.root(i) == i) rt.pb(i);
	ll l = 0, r = 1e13;
	while(l < r){
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
