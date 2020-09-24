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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int x[mxN], vis[mxN];
int mx = 0, bst = 0;

void dfs0(int cur, int prev, int dist){
	if(dist > mx) bst = cur, mx = dist;
	for(int u : g[cur]) if(u != prev && !vis[u] && x[u] == 1){
		dfs0(u, cur, dist + 1);
	}
}

void dfs(int cur, int prev, int dist){
	if(dist > mx) mx = dist;
	for(int u : g[cur]) if(x[u] == 1 && u != prev){
		dfs(u, cur, dist + 1);
	}
}

vi good;

void dfs1(int cur, int dist){
	vis[cur] = 1;
	if(dist == mx) good.pb(cur);
	for(int u : g[cur]) if(!vis[u] && x[u] == 1){
		dfs1(u, dist + 1);
	}
}

pi p[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	int mn = 1e9;
	rep(i, n) cin >> x[i], mn = min(mn, x[i]);
	if(mn != 1){
		cout << mn << "/1" << endl;
		return 0;
	}
	int ans = 1;
	rep(i, n) if(!vis[i] && x[i] == 1){
		mx = 0;
		bst = 0;
		dfs0(i, -1, 1);
		mx = 0;
		dfs(bst, -1, 1);
		good = {bst};
		dfs1(bst, 1);
		rep(j, good.size()){
			for(int u : g[good[j]]){
				if(x[u] == 2){
					if(mx > p[u].fi) p[u].se = p[u].fi, p[u].fi = mx;
					else if(mx > p[u].se) p[u].se = mx;
				}
			}
		}
		ans = max(ans, mx);
	}
	rep(i, n) if(x[i] == 2){
		if(p[i].fi == p[i].se && p[i].fi == ans){
			cout << "2/" << ans * 2 + 1 << endl;
			return 0;
		}
	}
	cout << "1/" << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
