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

vi g[mxN];
int de[mxN], d[mxN], dem[mxN];
int ord[mxN], ord1[mxN], st[mxN], en[mxN];
int p[22][mxN], pr[mxN];
int cr = 0, nm = 0;

void dfs(int cur, int prev){
	ord[cr++] = cur;
	st[cur] = nm++;
	p[0][cur] = prev;
	repn(i, 1, 22) p[i][cur] = p[i - 1][p[i - 1][cur]];
	for(int x : g[cur]) if(x != prev) dfs(x, cur);
	en[cur] = nm++;
}

bool up(int a, int b){
	return (st[a] < st[b] && en[a] > en[b]);
}

int lca(int a, int b){
	if(up(a, b)) return a;
	if(up(b, a)) return b;
	for(int i = 21; i >= 0; i--) if(!up(p[i][a], b)) a = p[i][a];
	assert(up(p[0][a], b));
	return p[0][a];
}

void dfs0(int cur, int prev, int dep = 0){
	int cnt = 0;
	d[cur] = dep;
	pr[cur] = prev;
	dem[cur] = 1e9;
	for(int x : g[cur]) if(x != prev){
		dfs0(x, cur, dep + 1);
		cnt++;
		de[cur] = max(de[cur], de[x] + 1);
		dem[cur] = min(dem[cur], dem[x] + 1);
	}
	if(!cnt) de[cur] = 0, dem[cur] = 0;
}

bool cmp(int a, int b){
	return de[a] > de[b];
}

bool cmp1(int a, int b){
	return dem[a] < dem[b];
}

void solve(){
	int n;
	cin >> n;
	rep(i, n) g[i].clear(), de[i] = 0, d[i] = 0, pr[i] = 0;
	rep(i, 22) rep(j, n) p[i][j] = 0;
	cr = 0, nm = 0;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs0(0, -1);
	rep(i, n){
		sort(all(g[i]), cmp);
		int mn = 1e9, ind = -1;
		rep(j, g[i].size()) if(g[i][j] != pr[i]){
			if(dem[g[i][j]] < mn) ind = j, mn = dem[g[i][j]];
		}
		if(ind != -1){
			swap(g[i][ind], g[i][g[i].size() - 1]);
			if(g[i].size() > 1) sort(all(g[i]) - 1, cmp);
		}
	}
	sort(all(g[0]), cmp1);
	dfs(0, 0);
	int ans = 0;
	rep(i, n){
		int j = i + 1;
		if(j == n) j = 0;
		int dist = d[ord[i]] + d[ord[j]] - (2 * d[lca(ord[i], ord[j])]);
		ans = max(ans, dist);
	}
	cout << ans << '\n';
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
