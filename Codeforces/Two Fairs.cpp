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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, a, b;
vi g[mxN];
int vis[mxN];

void dfs(int cur){
	vis[cur] = 1;
	for(int x : g[cur]) if(!vis[x] && x != a) dfs(x);
}

void dfs1(int cur){
	vis[cur] = 1;
	for(int x : g[cur]) if(!vis[x] && x != b) dfs1(x);
}

void solve(){
	cin >> n >> m >> a >> b;
	a--, b--;
	rep(i, n) g[i].clear();
	rep(i, m){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	set<int> st, st1;
	rep(i, n) vis[i] = 0;
	dfs(b);
	rep(i, n) if(!vis[i] && i != a) st.insert(i);
	rep(i, n) vis[i] = 0;
	dfs1(a);
	rep(i, n) if(!vis[i] && i != b) st1.insert(i);
	ll ans = 0LL;
	for(int x : st){
		if(st1.find(x) == st1.end()) ans += (int)(st1.size());
		else ans += (int)(st1.size()) - 1;
	}
	cout << ans << endl;
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
