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
#define ar array

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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	ld w, h;
	cin >> w >> h;
	vector<ar<ld, 3>> p(n);
	rep(i, n) cin >> p[i][0] >> p[i][1] >> p[i][2];
	vector<pair<ld, pair<ll, ll>>> ed;
	rep(i, n) repn(j, i + 1, n){
		ld dist = sqrtl((ld)(sq(p[i][1] - p[j][1]) + sq(p[i][0] - p[j][0]))) - (p[i][2] + p[j][2]);
		ed.pb(mp(dist, mp(i, j)));
	}
	//n is up, n + 1 is down, n + 2 is left, n + 3 is right
	rep(i, n){
		ed.pb(mp(h - p[i][1] - p[i][2], mp(i, n)));
		ed.pb(mp(p[i][1] - p[i][2], mp(i, n + 1)));
		ed.pb(mp(p[i][0] - p[i][2], mp(i, n + 2)));
		ed.pb(mp(w - p[i][0] - p[i][2], mp(i, n + 3)));
	}
	sort(all(ed));
	vector<pair<pair<ld, ll>, ll>> vis(m);
	rep(i, m) cin >> vis[i].fi.fi >> vis[i].fi.se, vis[i].se = i;
	sort(all(vis));
	int ind = 0;
	DSU dsu(n + 4);
	vector<string> ans(m);
	rep(i, m){
		//updates
		ld cur = (ld)(2.0 * vis[i].fi.fi);
		while(ind < (int)ed.size() && ed[ind].fi < cur){
			dsu.merge(ed[ind].se.fi, ed[ind].se.se);
			ind++;
		}
		//casework on answer
		string nw = "";
		if(vis[i].fi.se == 1){
			nw += '1';
			if(!dsu.sameset(n + 1, n + 2) && !dsu.sameset(n + 1, n + 3) && !dsu.sameset(n, n + 1)) nw += '2';
			if(!dsu.sameset(n + 1, n + 2) && !dsu.sameset(n + 2, n + 3) && !dsu.sameset(n, n + 1) && !dsu.sameset(n, n + 3)) nw += '3';
			if(!dsu.sameset(n + 1, n + 2) && !dsu.sameset(n + 2, n + 3) && !dsu.sameset(n, n + 2)) nw += '4';
		}
		if(vis[i].fi.se == 2){
			if(!dsu.sameset(n + 1, n + 2) && !dsu.sameset(n + 1, n + 3) && !dsu.sameset(n, n + 1)) nw += '1';
			nw += '2';
			if(!dsu.sameset(n + 1, n + 3) && !dsu.sameset(n + 2, n + 3) && !dsu.sameset(n, n + 3)) nw += '3';
			if(!dsu.sameset(n, n + 1) && !dsu.sameset(n + 2, n + 3) && !dsu.sameset(n, n + 2) && !dsu.sameset(n + 1, n + 3)) nw += '4';
		}
		if(vis[i].fi.se == 3){
			if(!dsu.sameset(n + 1, n + 2) && !dsu.sameset(n + 2, n + 3) && !dsu.sameset(n, n + 1) && !dsu.sameset(n, n + 3)) nw += '1';
			if(!dsu.sameset(n + 1, n + 3) && !dsu.sameset(n + 2, n + 3) && !dsu.sameset(n, n + 3)) nw += '2';
			nw += '3';
			if(!dsu.sameset(n, n + 2) && !dsu.sameset(n, n + 3) && !dsu.sameset(n, n + 1)) nw += '4';
		}
		if(vis[i].fi.se == 4){
			if(!dsu.sameset(n + 1, n + 2) && !dsu.sameset(n + 2, n + 3) && !dsu.sameset(n, n + 2)) nw += '1';
			if(!dsu.sameset(n, n + 1) && !dsu.sameset(n + 2, n + 3) && !dsu.sameset(n, n + 2) && !dsu.sameset(n + 1, n + 3)) nw += '2';
			if(!dsu.sameset(n, n + 2) && !dsu.sameset(n, n + 3) && !dsu.sameset(n, n + 1)) nw += '3';
			nw += '4';
		}
		ans[vis[i].se] = nw;
	}
	rep(i, m) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
