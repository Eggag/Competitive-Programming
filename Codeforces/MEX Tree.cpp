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

int n;
vi g[mxN];
int st[mxN], en[mxN], d[mxN], di[mxN], p[mxN];
int tim = 0;
int up[22][mxN];

void dfs(int cur, int prev, int ds = 0){
	st[cur] = tim++;
	up[0][cur] = prev;
	d[cur] = 1;
	di[cur] = ds;
	p[cur] = prev;
	repn(i, 1, 22) up[i][cur] = up[i - 1][up[i - 1][cur]];
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur, ds + 1);
		d[cur] += d[x];
	}
	en[cur] = tim++;
}

bool upper(int a, int b){
	return (st[a] <= st[b] && en[a] >= en[b]);
}

int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	int cr = a;
	for(int i = 21; i >= 0; i--) if(!upper(up[i][cr], b)) cr = up[i][cr];
	return up[0][cr];
}

int dist(int a, int b){
	return di[a] + di[b] - 2 * di[lca(a, b)];
}

bool onPath(int x, int a, int b){
	int c = lca(a, b);
	if((upper(x, a) || upper(x, b)) && upper(c, x)) return 1;
	return 0;
}

pi lst = mp(-1, -1);
ll one = 0LL, two = 0LL;

ll f(int a, int b){
	int dis = dist(a, b);
	if(a != lst.fi){
		one = 1LL;
		for(int x : g[a]){
			if(dist(x, b) > dis){
				ll sb = (ll)(d[x]);
				if(x == p[a]) sb = n - d[a];
				one += sb;
			}
		}
	}
	if(b != lst.se){
		two = 1LL;
		for(int x : g[b]){
			if(dist(x, a) > dis){
				ll sb = (ll)(d[x]);
				if(x == p[b]) sb = n - d[b];
				two += sb;
			}
		}
	}
	lst = mp(a, b);
	return one * two;
}

void solve(){
	cin >> n;
	tim = 0;
	lst = {-1, -1};
	rep(i, n + 1) g[i].clear();
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, 0);
	vector<ll> ans(n + 1, 0LL);
	for(int x : g[0]) ans[1] += (ll)(1LL * (ll)(n - d[x] - 1) * (ll)(d[x]));
	ans[1] /= 2;
	ans[1] += (ll)(n - 1);
	ans[2] = f(0, 1);
	int u = 0, v = 1;
	repn(i, 3, n + 1){
		if(onPath(i - 1, u, v)) ans[i] = ans[i - 1];
		else{
			int cd = u, ef = v;
			if(!upper(u, i - 1) && !upper(v, i - 1)) break;
			if(!upper(u, i - 1) && upper(v, i - 1)) v = i - 1;
			else if(upper(u, i - 1) && !upper(v, i - 1)) u = i - 1;
			else{
				if(upper(u, v)) v = i - 1;
				else u = i - 1;
			}
			if(!onPath(cd, u, v) || !onPath(ef, u, v)) break;
			ans[i] = f(u, v);
		}
	}
	ll sbt = ans[n];
	for(int i = n - 1; i >= 1; i--){
		ans[i] -= sbt;
		sbt += ans[i];
	}
	ll tot = 0LL;
	repn(i, 1, n + 1) tot += ans[i];
	ll n1 = (ll)(n);
	ans[0] = ((n1 * (n1 - 1)) / 2) - tot;
	rep(i, n + 1) cout << ans[i] << " ";
	cout << '\n';
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
