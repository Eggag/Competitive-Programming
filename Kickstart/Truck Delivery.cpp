#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
#define sz(x) (int)(x.size())
const int mxN = 5e4 + 5;
const int inf = 1e18 + 10;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct Node{
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){}
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi){
		if(lo + 1 < hi){
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = gcd(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R){
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		int ret = gcd(l->query(L, R), r->query(L, R));
		return ret;
	}
	void set(int L, int R, int x){
		if(R <= lo || hi <= L) return;
		if(L <= lo && hi <= R) mset = val = x, madd = 0;
		else{
			push(), l->set(L, R, x), r->set(L, R, x);
			val = gcd(l->val, r->val);
		}
	}
	void add(int L, int R, int x){
		if(R <= lo || hi <= L) return;
		if(L <= lo && hi <= R) {
			if(mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else{
			push(), l->add(L, R, x), r->add(L, R, x);
			val = gcd(l->val, r->val);
		}
	}
	void push(){
		if(!l){
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if(mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if(madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

template<bool VALS_EDGES> struct HLD{
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
	void dfsSz(int v){
		if(par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for(int& u : adj[v]){
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v){
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template<class B> void process(int u, int v, B op){
		for(; rt[u] != rt[v]; v = par[rt[v]]){
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v] + 1);
		}
		if(depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	void modifyPath(int u, int v, int val){
		process(u, v, [&](int l, int r){ tree->set(l, r, val); });
	}
	int queryPath(int u, int v){
		int res = 0;
		process(u, v, [&](int l, int r) {
				res = gcd(res, tree->query(l, r));
		});
		return res;
	}
};

vector<vi> g;

void solve(){
	int n, q;
	cin >> n >> q;
	rep(i, g.size()) g[i].clear();
	g.resize(n);
	vector<array<int, 4>> ed;
	rep(i, n - 1){
		int a, b, l, x;
		cin >> a >> b >> l >> x;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		array<int, 4> ar = {l, a, b, x};
		ed.pb(ar);
	}
	HLD<true> hld(g);
	rep(i, ed.size()){
		hld.modifyPath(ed[i][1], ed[i][2], ed[i][3]);
	}
	sort(all(ed));
	reverse(all(ed));
	vector<array<int, 3>> p(q);
	//0 is weight, 1 is city
	rep(i, q){
		cin >> p[i][1] >> p[i][0];
		p[i][1]--;
		p[i][2] = i;
	}
	sort(all(p)); //we sort by weight
	reverse(all(p));
	int ind = 0;
	vi ans(q, 0);
	rep(i, q){
		while(ind < (n - 1) && ed[ind][0] > p[i][0]){
			hld.modifyPath(ed[ind][1], ed[ind][2], 0);
			ind++;
		}
		ans[p[i][2]] = hld.queryPath(0, p[i][1]);
	}
	rep(i, q) cout << ans[i] << " ";
	cout << '\n';
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
