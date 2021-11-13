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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
vi g[mxN];
int pos = 0, tot = 0;
int d[mxN], a[mxN], f[mxN];
int cnt = 0;

void dfs(int cur, int prev){
	d[cur] = a[cur];
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		d[cur] ^= d[x];
		f[cur] |= f[x];
	}
	if(f[cur] && !d[cur] && k > 2) pos = 1;
	if(d[cur] == tot) if(!f[cur]) f[cur] = 1, cnt++;
	if(d[cur] == (tot ^ d[cur])) pos = 1;
}

void solve(){
	cin >> n >> k;
	pos = 0, tot = 0, cnt = 0;
	rep(i, n) cin >> a[i], tot ^= a[i];
	rep(i, n) g[i].clear(), d[i] = 0, f[i] = 0;
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0, -1);
	if(cnt > 1 && k > 2) pos = 1;
	cout << (pos ? "YES" : "NO") << '\n';
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
