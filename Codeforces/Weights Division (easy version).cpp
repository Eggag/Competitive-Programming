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

int n;
ll s;
vector<pair<int, int>> g[mxN], g1[mxN];

ll d[mxN];

bool cmp(pair<pi, int> a, pair<pi, int> b){
	return (min(d[a.fi.fi], d[a.fi.se]) * (ll)((a.se + 1) / 2)) > (min(d[b.fi.fi], d[b.fi.se]) * (ll)((b.se + 1) / 2));
}

vector<pair<pi, int>> ed;

ll tot = 0LL;

void dfs0(int cur, int prev){
	int f = 0;
	for(pair<int, ll> x : g1[cur]) if(x.fi != prev){
		f = 1;
		dfs0(x.fi, cur);
		d[cur] += d[x.fi];
	}
	if(!f) d[cur] = 1LL;
}

multiset<pair<pi, int>, decltype(cmp)*> pq(cmp);

void solve(){
	cin >> n >> s;
	ed.clear();
	rep(i, n) g1[i].clear();
	rep(i, n - 1){
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		ed.pb(mp(mp(u, v), w));
		g1[u].pb(mp(v, w));
		g1[v].pb(mp(u, w));
	}
	rep(i, n) d[i] = 0LL;
	dfs0(0, -1);
	pq.clear();
	rep(i, n - 1) pq.insert(ed[i]);
	tot = 0LL;
	for(pair<pi, int> cur : pq){
		tot += min(d[cur.fi.fi], d[cur.fi.se]) * cur.se;
	}
	if(tot <= s){
		cout << 0 << endl;
		return;
	}
	rep(i, 21 * n){
		auto it = pq.begin();
		pair<pi, int> cur = *it;
		tot -= min(d[cur.fi.fi], d[cur.fi.se]) * cur.se;
		cur.se /= 2;
		tot += min(d[cur.fi.fi], d[cur.fi.se]) * cur.se;
		pq.erase(it);
		pq.insert(cur);
		if(tot <= s){
			cout << i + 1 << endl;
			return;
		}
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
