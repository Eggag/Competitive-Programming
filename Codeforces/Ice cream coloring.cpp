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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, mx = 1;
int s[mxN], col[mxN];
vi g[mxN], a[mxN];

bool cmp(int a, int b){
	return col[a] < col[b];
}

void dfs(int cur, int prev){
	int c = mx, ind = (int)(g[cur].size()) - 1;
	sort(all(g[cur]), cmp);
	for(int x : g[cur]) if(!col[x]){
		while(ind >= 0 && c == col[g[cur][ind]]) c--, ind--;
		col[x] = c--;
	}
	for(int u : a[cur]) if(u != prev) dfs(u, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n){
		cin >> s[i];
		rep(j, s[i]){
			int x;
			cin >> x;
			x--;
			g[i].pb(x);
		}
		mx = max(mx, s[i]);
	}
	rep(i, n - 1){
		int u, v;
		cin >> u >> v;
		u--, v--;
		a[u].pb(v);
		a[v].pb(u);
	}
	dfs(0, -1);
	cout << mx << '\n';
	rep(i, m){
		if(!col[i]) col[i] = 1;
		cout << col[i] << ' ';
	}
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
