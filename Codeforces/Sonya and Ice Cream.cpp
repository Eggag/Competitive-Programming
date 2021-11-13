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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
vector<pi> g[mxN];
int d[mxN], p[mxN];
int st[mxN], en[mxN];
int de[mxN];
int cnt = 0, nxt1 = 0, bd = 0;
int bst = 0, lw = 0;

void dfs(int cur, int prev, int dd = 0){
	p[cur] = prev;
	st[cur] = cnt++;
	de[cur] = dd;
	for(pi x : g[cur]) if(x.fi != prev){
		dfs(x.fi, cur, dd + 1);
		d[cur] = max(d[cur], d[x.fi] + x.se);
	}
	en[cur] = cnt++;
}

bool up(int a, int b){
	return (st[a] <= st[b] && en[a] >= en[b]);
}

void dfs1(int cur, int prev, int t, int ed = 0){
	if(~prev){
		if(d[cur] <= t && (d[cur] + ed) > t && de[prev] > bst){
			lw = cur;
			bst = de[prev];
		}
	}
	for(pi x : g[cur]) if(x.fi != prev) dfs1(x.fi, cur, t, x.se);
}

void dfs2(int cur, int prev, int t, int ed = 0){
	if(~prev){
		if(d[cur] <= t && (d[cur] + ed) > t && de[prev] > bst && up(nxt1, cur)){
			lw = cur;
			bst = de[prev];
		}
	}
	for(pi x : g[cur]) if(x.fi != prev) dfs2(x.fi, cur, t, x.se);
}


void dfs3(int cur, int prev, int bal, int uwu){
	if(cur == nxt1) return;
	if(bal > uwu) bd = 1;
	for(pi x : g[cur]) if(x.fi != prev) dfs3(x.fi, cur, bal + x.se, uwu);
}

bool check(int gs){
	if(d[0] <= gs) return 1;
	bst = 0, lw = 0;
	dfs1(0, -1, gs);
	int k1 = 1, ff = 0;
	int u = p[lw], pr = lw, pr1 = -1;
	int nxt = -1;
	if(k1 == k){
		ff = 1;
		goto owo;
	}
	while(~u){
		int f = 0;
		for(pi x : g[u]) if(x.fi != pr && (d[x.fi] + x.se) > gs && x.fi != p[u]){
			f++;
			nxt = x.fi;
		}
		k1++;
		pr1 = pr;
		pr = u, u = p[u];
		if(f > 1) return 0;
		if(f == 1) break;
		if(k1 == k){
			ff = 1;
			break;
		}
	}
	owo:;
	int lstm = pr;
	nxt1 = nxt;
	if(ff || (nxt != -1 && ~u)){
		bd = 0;
		dfs3(pr, pr1, 0, gs);
		if(bd) return 0;
	}
	if(nxt == -1) return 1;
	if(k1 == k) return 0;
	nxt1 = nxt;
	lw = 0, bst = 0;
	dfs2(0, -1, gs);
	k1++;
	if(lw == nxt) return 1;
	u = p[lw], pr = lw;
	if(u == lstm) return 1;
	if(k1 == k) return 0;
	while(~u){
		int f = 0;
		for(pi x : g[u]) if(x.fi != pr && (d[x.fi] + x.se) > gs && x.fi != p[u]) f++;
		if(f > 0) return 0;
		pr = u, u = p[u];
		k1++;
		if(u == lstm) return 1;
		if(k1 == k) return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n - 1){
		int u, v, d;
		cin >> u >> v >> d;
		u--, v--;
		g[u].pb(mp(v, d));
		g[v].pb(mp(u, d));
	}
	dfs(0, -1);
	int l = 0, r = 1e9;
	while(l < r){
		int mid = (l + r) / 2;
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
