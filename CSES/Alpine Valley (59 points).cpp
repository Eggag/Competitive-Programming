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
 
int n, s, q, e;
int sh[100005];
int a[100005], b[100005];
ll w[100005];
vector<pair<int, ll>> g[1005];
vi g1[100005];
 
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
 
ll dist[1005]; //don't forget to initialize to inf, change to ll if necessary
 
void dijkstra(int t){
	//find the shortest paths to t
	rep(i, 1005) dist[i] = 1e18;
	dist[t] = 0;
	set<pair<ll, int>> q;
	q.insert(mp(dist[t], t));
	while(!q.empty()){
		int u = q.begin() -> se;
		q.erase(q.begin());
		for(pair<int, ll> x : g[u]){
			if((dist[u] + x.se) < dist[x.fi]){
				q.erase(mp(dist[x.fi], x.fi));
				dist[x.fi] = dist[u] + x.se;
				q.insert(mp(dist[x.fi], x.fi));
			}
		}
	}
}

int tim = 0;
int st[100005], en[100005];

void dfs(int cur, int prev){
	st[cur] = tim++;
	for(int x : g1[cur]) if(x != prev) dfs(x, cur);
	en[cur] = tim++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> s >> q >> e;
	e--;
	rep(i, n - 1){
		cin >> a[i] >> b[i] >> w[i];
		a[i]--, b[i]--;
		g1[a[i]].pb(b[i]);
		g1[b[i]].pb(a[i]);
	}
	dfs(e, -1);
	rep(i, s) cin >> sh[i], sh[i]--;
	rep(i, q){
		int t, r;
		cin >> t >> r;
		t--, r--;
		if(n * q <= 1000000){
			rep(j, n) g[j].clear();
			DSU dsu(n);
			rep(j, n - 1) if(j != t){
				dsu.merge(a[j], b[j]);
				g[a[j]].pb(mp(b[j], w[j]));
				g[b[j]].pb(mp(a[j], w[j]));
			}
			if(dsu.sameset(r, e)){
				cout << "escaped" << endl;
			}
			else{
				dijkstra(r);
				ll ans = 1e18;
				rep(j, s) ans = min(ans, dist[sh[j]]);
				if(ans == 1e18) cout << "oo" << endl;
				else cout << ans << endl;
			}
		}
		else{
			int nm = a[t];
			if(st[b[t]] > st[a[t]]) nm = b[t];
			if(st[r] >= st[nm] && en[r] <= en[nm]){
				cout << 0 << endl;
				continue;
			}
			cout << "escaped" << endl;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
