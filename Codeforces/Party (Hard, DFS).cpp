#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int ret = 0;
vi g[2005];
int ba[2005][2005];
int vis[2005];
vi e;

void dfs(int cur, int prev){
	if(vis[cur]) return;
	vis[cur] = 1;
	e.pb(cur);
	ret++;
	for(int u : g[cur]) if(u != prev) dfs(u, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int k;
	cin >> k;
	memset(vis, 0, sizeof(vis));
	memset(ba, 0, sizeof(ba));
	rep(i, k){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	int m;
	cin >> m;
	rep(i, m){
		int x, y;
		cin >> x >> y;
		x--, y--;
		ba[y][x] = ba[x][y] = 1;
	}
	int ans = 0;
	rep(i, n) if(!vis[i]){
		e.clear();
		ret = 0;
		dfs(i, -1);
		bool f = 1;
		rep(j, e.size()) rep(k, e.size()) if(ba[e[j]][e[k]]) f = 0;
		if(f) ans = max(ans, ret);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
