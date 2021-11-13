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

vi g[mxN], g1[mxN];
vi tp;
int vis[mxN], d[mxN];
ll v[mxN], t[mxN], d1[mxN];
map<pi, int> sp;

void dfs0(int cur){
	vis[cur] = 1;
	for(int x : g[cur]){
		if(!vis[x]){
			g1[cur].pb(x);
			g1[x].pb(cur);
			sp[mp(cur, x)] = 1;
			dfs0(x);
		}
	}
}

void dfs1(int cur, int prev, int ds = 0){
	d[cur] = ds;
	for(int x : g1[cur]) if(x != prev) dfs1(x, cur, ds + 1);
}

void dfs2(int cur, int prev){
	ll cr = v[cur];
	for(int x : g1[cur]) if(x != prev){
		dfs2(x, cur);
		cr += d1[x];
	}
	if(cur) d1[cur] = t[cur] - cr;
	else d1[cur] = cr;
}

void solve(){
	int n, m;
	cin >> n >> m;
	ll dif = 0LL;
	rep(i, n) cin >> v[i];
	rep(i, n) cin >> t[i], dif += t[i] - v[i];
	rep(i, n + 1) g[i].clear(), g1[i].clear(), vis[i] = 0;
	rep(i, n + 1) d[i] = 0, d1[i] = 0LL;
	vector<pi> ed;
	sp.clear();
	rep(i, m){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
		ed.pb(mp(x, y));
	}
	dfs0(0);
	dfs1(0, -1);
	int cyc = 0;
	rep(i, m){
		if(sp.find(ed[i]) == sp.end() && sp.find(mp(ed[i].se, ed[i].fi)) == sp.end()){
			if(abs(d[ed[i].fi] - d[ed[i].se]) % 2 == 0) cyc = 1;
		}
	}
	if(cyc){
		if(dif % 2 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
	else{
		dfs2(0, -1);
		cout << (d1[0] == t[0] ? "YES" : "NO") << '\n';
	}
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
