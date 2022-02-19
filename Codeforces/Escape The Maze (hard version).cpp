//USACO HERE I COME
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

vi g[mxN];
int uwu[mxN], vis[mxN];
int res = 0;
vi le;

void dfs(int cur, int prev, int d = 0){
	uwu[cur] = d++;
	int cnt = 0;
	for(int x : g[cur]) if(x != prev) dfs(x, cur, d), cnt++;
	if(!cnt) le.pb(cur);
}

void dfs1(int cur, int prev){
	if(uwu[cur] >= vis[cur] - 1){
		res++;
		return;
	}
	for(int x : g[cur]) if(x != prev) dfs1(x, cur);
}

void solve(){
	int n, k;
	cin >> n >> k;
	rep(i, n + 1) g[i].clear(), vis[i] = 0;
	le.clear();
	res = 0;
	vi x(k);
	rep(i, k) cin >> x[i];
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	queue<int> q;
	rep(i, k){
		vis[x[i] - 1] = 1;
		q.push(x[i] - 1);
	}
	while(!q.empty()){
		int cr = q.front();
		q.pop();
		for(int u : g[cr]) if(!vis[u]){
			vis[u] = vis[cr] + 1;
			q.push(u);
		}
	}
	for(int l : le){
		if(vis[l] - 1 > uwu[l]){
			cout << "-1\n";
			return;
		}
	}
	dfs1(0, -1);
	cout << res << '\n';
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

