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

vi g[mxN];
int l[mxN];
int mn[mxN];

void dfs(int cur, int prev){
	if(l[cur]) mn[cur] = 0;
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		mn[cur] = min(mn[cur], mn[x] + 1);
	}
}

int ans = 0;

void dfs1(int cur, int prev, int dist){
	if(dist >= mn[cur]){
		ans++;
		return;
	}
	for(int x : g[cur]) if(x != prev) dfs1(x, cur, dist + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("atlarge.in", "r", stdin);
	freopen("atlarge.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	k--;
	rep(i, n) mn[i] = 1e9;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i, n) if(g[i].size() == 1) l[i] = 1;
	if(l[k]){
		cout << 1 << endl;
		return 0;
	}
	dfs(k, -1);
	dfs1(k, -1, 0);
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
