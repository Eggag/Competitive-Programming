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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
pi ans[mxN];
map<int, int> cnt[mxN];

bool cmp(int a, int b){
	return (int)(cnt[a].size()) > (int)(cnt[b].size());
}

void dfs(int cur, int prev, int de = 0){
	for(int x : g[cur]) if(x != prev) dfs(x, cur, de + 1);
	cnt[cur][de] = 1;
	sort(all(g[cur]), cmp);
	int f = 0;
	pi bst = mp(1, 0);
	for(int x : g[cur]) if(x != prev){
		if(ans[x].fi == bst.fi) bst.se = min(bst.se, ans[x].se + 1);
		else if(ans[x].fi > bst.fi) bst = mp(ans[x].fi, ans[x].se + 1);
		if(!f){
			swap(cnt[x], cnt[cur]);
			cnt[cur][de]++;
			f = 1;
		}
		else{
			for(pi y : cnt[x]){
				cnt[cur][y.fi] += y.se;
				int nw = cnt[cur][y.fi];
				if(nw == bst.fi) bst.se = min(bst.se, y.fi - de);
				else if(nw > bst.fi) bst = mp(nw, y.fi - de);
			}
		}
	}
	ans[cur] = bst;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0, -1);
	rep(i, n) cout << ans[i].se << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
