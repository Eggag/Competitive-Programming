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
const int mxN = 8e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int cnt[mxN], d1[mxN], d[mxN];
int st[mxN], en[mxN];
int up[mxN][25];
int ans = 0;
int ti = 0;

void dfs0(int cur, int prev = 0){
	st[cur] = ti++;
	up[cur][0] = prev;
	d[cur] = 1;
	repn(i, 1, 21) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for(int x : g[cur]) if(x != prev){
		dfs0(x, cur);
		d[cur] += d[x];
	}
	en[cur] = ti++;
}

bool upper(int a, int b){
	return (st[a] <= st[b] && en[a] >= en[b]);
}

int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	int cr = a;
	for(int i = 20; i >= 0; i--) if(!upper(up[cr][i], b)) cr = up[cr][i];
	return up[cr][0];
}

void dfs(int cur, int prev){
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		d1[cur] += d1[x];
	}
	if(prev != -1 && d[cur] == d1[cur]) ans++;
}

void solve(){
	int n;
	cin >> n;
	rep(i, n) g[i].clear(), cnt[i] = 0, d[i] = 0, d1[i] = 0;
	rep(i, n) st[i] = 0, en[i] = 0;
	rep(i, n) rep(j, 25) up[i][j] = 0;
	ans = 0, ti = 0;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs0(0);
	vector<pi> f(n);
	rep(i, n) cin >> f[i].fi, f[i].se = i;
	sort(all(f));
	int cnt = 1, lc = f[0].se;
	repn(i, 1, n){
		if(f[i].fi == f[i - 1].fi){
			cnt++;
			lc = lca(lc, f[i].se);
		}
		else{
			d1[lc] += cnt;
			cnt = 1;
			lc = f[i].se;
		}
	}
	d1[lc] += cnt;
	dfs(0, -1);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
