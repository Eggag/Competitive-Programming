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

int n;
ll a[mxN];
ll sum = 0LL;
ll ans = 0LL;
ll d[mxN];
vi g[mxN];

ll dfs(int cur, int prev, ll dep){
	d[cur] = a[cur];
	ans += (ll)(a[cur] * dep);
	for(int u : g[cur]) if(u != prev){
		d[cur] += dfs(u, cur, dep + 1);
	}
	return d[cur];
}

void dfs1(int cur, int prev, ll pr){
	//we try to go to a node
	for(int u : g[cur]) if(u != prev){
		ans = max(ans, pr - d[u] + (sum - d[u]));
		dfs1(u, cur, pr - d[u] + (sum - d[u]));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> a[i], sum += a[i];
	rep(i, n - 1){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0, -1, 0);
	dfs1(0, -1, ans);
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
