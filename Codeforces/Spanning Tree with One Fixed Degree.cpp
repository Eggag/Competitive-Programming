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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int deg[mxN], vis[mxN];

void dfs(int cur){
	vis[cur] = 1;
	for(int u : g[cur]) if(!vis[u]) dfs(u);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, d;
	cin >> n >> m >> d;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		deg[a]++, deg[b]++;
	}
	if(deg[0] < d){
		cout << "NO" << endl;
		return 0;
	}
	vis[0] = 1;
	vector<pi> ans;
	set<int> need;
	for(int u : g[0]) if(!vis[u]){
		ans.pb({u, 0});
		need.insert(u);
		dfs(u);
	}
	if(need.size() > d){
		cout << "NO" << endl;
		return 0;
	}
	for(int u : g[0]) if(need.find(u) == need.end()){
		if(need.size() == d) break;
		ans.pb({u, 0});
		need.insert(u);
	}
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	queue<int> q;
	for(int x : need) q.push(x), vis[x] = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int u : g[cur]) if(!vis[u]){
			vis[u] = 1;
			ans.pb({cur, u});
			q.push(u);
		}
	}
	cout << "YES" << endl;
	for(pi x : ans) cout << x.fi + 1 << " " << x.se + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
