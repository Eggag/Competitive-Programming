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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, num = 0, l = 0;
int t[mxN], ans[mxN];
vector<pi> sta[mxN], en[mxN];
vector<vi> up;
int st[mxN], fin[mxN];
set<pi> se[mxN];
vi g[mxN];

void dfs(int cur, int prev = 0){
	st[cur] = num++;
	up[cur][0] = prev;
	repn(i, 1, l + 1) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for(int x : g[cur]) if(x != prev) dfs(x, cur);
	fin[cur] = num++;
}
 
bool upper(int a, int b){
	return st[a] <= st[b] && fin[a] >= fin[b];
}
 
int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	for(int i = l; i >= 0; i--) if(!upper(up[a][i], b)) a = up[a][i];
	return up[a][0];
}

void dfs1(int cur, int prev){
	//we merge from the guys before
	for(int x : g[cur]) if(x != prev){
		dfs1(x, cur);
		if(se[x].size() > se[cur].size()) swap(se[x], se[cur]);
		for(auto y : se[x]) se[cur].insert(y);
	}
	//insert
	for(pi x : sta[cur]) se[cur].insert(x);
	//then do
	auto it = se[cur].lb({t[cur], -1});
	while(it != se[cur].end()){
		pi cur1 = *it;
		if(cur1.fi != t[cur]) break;
		ans[cur1.se] = 1;
		auto it1 = next(it);
		se[cur].erase(it);
		it = it1;
	}
	//then delete
	for(pi x : en[cur]){
		auto it = se[cur].find(x);
		if(it != se[cur].end()) se[cur].erase(it);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> t[i];
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b), g[b].pb(a);
	}
	up.resize(n + 1);
	while((1 << l) <= n) l++;
	rep(i, n) up[i].resize(l + 1);
	dfs(0);
	rep(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		int lc = lca(a, b);
		sta[a].pb(mp(c, i));
		sta[b].pb(mp(c, i));
		en[lc].pb(mp(c, i));
	}
	dfs1(0, -1);
	rep(i, m) cout << ans[i];
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
