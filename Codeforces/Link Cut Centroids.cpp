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

int d[mxN], p[mxN], h[mxN];
vi g[mxN];

void dfs(int cur, int prev, int he){
	d[cur] = 1;
	p[cur] = prev;
	h[cur] = he;
	for(int u : g[cur]) if(u != prev){
		dfs(u, cur, he + 1);
		d[cur] += d[u];
	}
}

void solve(){
	int n;
	cin >> n;
	rep(i, n) g[i].clear(), d[i] = 0, p[i] = 0;
	int a, b;
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		a = x, b = y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0, -1, 0);
	int mn = 1e9;
	vi bst;
	rep(i, n){
		int mx = 0;
		for(int u : g[i]) if(u != p[i]) mx = max(mx, d[u]);
		mx = max(mx, n - d[i]);
		if(mx == mn) bst.pb(i);
		if(mx < mn){
			mn = mx;
			bst = {i};
		}
	}
	if(bst.size() == 1){
		cout << a << " " << b << endl;
		cout << a << " " << b << endl;
	}
	else{
		assert((int)bst.size() == 2);
		if(h[bst[1]] < h[bst[0]]) swap(bst[0], bst[1]);
		//so h[bst[0]] < h[bst[1]]
		int res = p[bst[1]];
		for(int u : g[bst[1]]){
			if(u != p[bst[1]]){
				res = u + 1;
				break;
			}
		}
		cout << bst[1] + 1 << " " << res << endl;
		cout << bst[0] + 1 << " " << res << endl;
	}
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
	- Array bounds
	- Special cases
Be careful!
*/
