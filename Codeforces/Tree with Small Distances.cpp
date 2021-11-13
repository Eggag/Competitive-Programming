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
int d[mxN], p[mxN];

void dfs(int cur, int prev, int di){
	d[cur] = di;
	p[cur] = prev;
	for(int x : g[cur]) if(x != prev) dfs(x, cur, di + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n - 1){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0, -1, 0);
	int ans = 0;
	set<pi> st;
	rep(i, n) if(d[i] > 2) st.insert(mp(n - d[i], i));
	vi v(n, 0);
	while(!st.empty()){
		pi cur = *st.begin();
		st.erase(st.begin());
		int up = p[cur.se];
		ans++;
		if(!v[up]){
			auto it = st.find(mp(n - d[up], up));
			if(it != st.end()) st.erase(it);
			for(int x : g[up]){
				auto it = st.find(mp(n - d[x], x));
				if(it != st.end()) st.erase(it);
			}
			v[up] = 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
