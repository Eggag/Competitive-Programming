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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
vi g[mxN];
int c[mxN];

void dfs(int cur, int col){
	c[cur] = col;
	if(col){
		vi nxt;
		for(int x : g[cur]) if(!~c[x]) c[x] = 0, nxt.pb(x);
		for(int x : nxt) dfs(x, col ^ 1);
	}
	else for(int x : g[cur]) if(!~c[x]) dfs(x, col ^ 1);
}

void solve(){
	cin >> n >> m;
	rep(i, n) c[i] = -1, g[i].clear();
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, 1);
	int tot = 0;
	rep(i, n){
		if(c[i] == -1){
			cout << "NO\n";
			return;
		}
		tot += c[i];
	}
	cout << "YES\n" << tot << '\n';
	rep(i, n) if(c[i]) cout << i + 1 << " ";
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
