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

vi g[mxN];
int deg[mxN], lf[mxN], nm[mxN];

void solve(){
	int n, k;
	cin >> n >> k;
	rep(i, n) g[i].clear(), deg[i] = 0, lf[i] = 0, nm[i] = 0;
	rep(i, n - 1){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
		deg[u]++, deg[v]++;
	}
	vi le;
	rep(i, n) if(deg[i] == 1) le.pb(i), lf[i] = 1;
	int ans = 0, ans1 = 0;
	rep(i, le.size()){
		int nd = -1;
		for(int x : g[le[i]]) if(!lf[x]) nd = x;
		if(nd == -1){
			if(k == 1) ans1++;
			continue;
		}
		nm[nd]++;
		if(nm[nd] == k){
			ans++;
			nm[nd] = 0;
			deg[nd] -= k;
			if(deg[nd] == 1) lf[nd] = 1, le.pb(nd);
		}
	}
	cout << ans + (ans1 / 2) << '\n';
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
