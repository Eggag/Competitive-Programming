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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int vis[mxN];
vi g[mxN], h[mxN];
pi p[mxN];

void dfs(int cur, int prev){
	int mx = 0, bst = -1;
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		if((int)(h[x].size()) > mx){
			mx = (int)(h[x].size());
			bst = x;
		}
	}
	int lst;
	if(bst != -1){
		swap(h[cur], h[bst]);
		lst = h[cur].back();
		h[cur].pop_back();
	}
	for(int x : g[cur]) if(x != prev && x != bst){
		rep(i, h[x].size() - 1) h[cur].pb(h[x][i]);
	}
	h[cur].pb(cur);
	for(int x1 = (int)g[cur].size() - 1; x1 >= 0; x1--) if(g[cur][x1] != prev){
		int x = g[cur][x1];
		if(x == bst) continue;
		h[cur].pb(h[x][(int)(h[x].size()) - 1]);
		h[x].clear();
	}
	if(bst != -1) h[cur].pb(lst);
	h[cur].pb(cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	assert((int)(h[0].size()) == 2 * n);
	int cr = 1;
	rep(i, 2 * n){
		if(!vis[h[0][i]]){
			p[h[0][i]].fi = cr++;
			vis[h[0][i]] = 1;
		}
		else p[h[0][i]].se = cr++;
	}
	rep(i, n) cout << p[i].fi << " " << p[i].se << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
