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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, u, v;
int ans = 0;
vi g[100005];
int U[100005]; //shortest path from u to i
int V[100005]; //shortest path from v to i

void dfs(int cur, int prev, int cnt, int f){
	if(f == 1) U[cur] = cnt;
	if(f == 2) V[cur] = cnt;
	for(int nxt : g[cur]) if(nxt != prev) dfs(nxt, cur, cnt + 1, f);
}

void dfs1(int cur, int prev){
	if(V[cur] <= U[cur]) return; //the other guy can get there faster
	ans = max(ans, V[cur] - 1);
	for(int nxt : g[cur]) if(nxt != prev) dfs1(nxt, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> u >> v;
	u--, v--;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(u, -1, 0, 1);
	dfs(v, -1, 0, 2);
	//rep(i, n) debug(U[i]);
	//rep(i, n) debug(V[i]);
	dfs1(u, -1);
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
