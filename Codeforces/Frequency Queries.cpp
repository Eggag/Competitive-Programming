#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

template<class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

int n, q;
int a[mxN], ans[mxN], cnt[mxN];
vi g[mxN];
vector<array<int, 3>> qs[mxN];
ordered_set<pi> ost;

void dfs(int cur, int prev){
	for(array<int, 3> y : qs[cur]){
		int l = y[0], k = y[1];
		int ind = ost.order_of_key(mp(l, 0));
		int uwu = ind + k - 1;
		/*
		cout << "======\n";
		debug(cur);
		debug2(l, k);
		debug(ind);
		debug(uwu);
		for(pi x: ost) debug2(x.fi, x.se);
		cout << "=====\n";
		*/
		if(uwu >= ost.size()) ans[y[2]] = -1;
		else{
			pi owo = *ost.find_by_order(uwu);
			ans[y[2]] = owo.se;
		}
	}
	for(int x : g[cur]) if(x != prev){
		//add
		if(cnt[a[x]]) ost.erase(ost.find(mp(cnt[a[x]], a[x])));
		ost.insert(mp(++cnt[a[x]], a[x]));
		dfs(x, cur);
		//remove
		ost.erase(ost.find(mp(cnt[a[x]]--, a[x])));
		if(cnt[a[x]]) ost.insert(mp(cnt[a[x]], a[x]));
	}
}

void solve(){
	cin >> n >> q;
	rep(i, n) cin >> a[i];
	ost.clear();
	rep(i, n + 1){
		g[i].clear();
		qs[i].clear();
		cnt[i] = 0;
	}
	repn(i, 1, n){
		int x;
		cin >> x; x--;
		g[i].pb(x);
		g[x].pb(i);
	}
	rep(i, q){
		int v, l, k;
		cin >> v >> l >> k;
		v--;
		array<int, 3> uwu = {l, k, i};
		qs[v].pb(uwu);
	}
	cnt[a[0]] = 1;
	ost.insert(mp(1, a[0]));
	dfs(0, -1);
	rep(i, q) cout << ans[i] << ' ';
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
