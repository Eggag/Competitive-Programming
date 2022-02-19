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

int n, q;
int x[mxN], ans[mxN];
vi g[mxN];
vector<pi> qs[mxN];
multiset<int> uwu[mxN];

void dfs(int cur, int prev){
	uwu[cur].insert(x[cur]);
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		if(uwu[x].size() > uwu[cur].size()) swap(uwu[x], uwu[cur]);
		for(int y : uwu[x]){
			uwu[cur].insert(y);
			if(uwu[cur].size() > 20) uwu[cur].erase(uwu[cur].begin());
		}
	}
	vi res(20, -1);
	int ind = 0;
	auto it = --uwu[cur].end();
	while(true){
		res[ind++] = *it;
		if(it == uwu[cur].begin()) break;
		it--;
	}
	for(pi qq : qs[cur]){
		assert(res[qq.fi] != -1);
		ans[qq.se] = res[qq.fi];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> q;
	rep(i, n) cin >> x[i];
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i, q){
		int v, k;
		cin >> v >> k;
		v--, k--;
		qs[v].pb(mp(k, i));
	}
	dfs(0, -1);
	rep(i, q) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
