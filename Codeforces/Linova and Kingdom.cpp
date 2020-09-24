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
const int MAXN = 2e6 + 100;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll d[MAXN], dpt[MAXN];
pair<ll, ll> d1[MAXN];
vi g[MAXN];

void dfs(int cur, int prev, ll nm){
	dpt[cur] = nm;
	d[cur] += 1LL;
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur, nm + 1);
		d[cur] += d[x];
	}
}

ll t[MAXN];

void dfs1(int cur, int prev){
	d1[cur].fi = 1LL;
	d1[cur].se = t[cur];
	for(int x : g[cur]) if(x != prev){
		dfs1(x, cur);
		d1[cur].fi += d1[x].fi;
		d1[cur].se += d1[x].se;
	}
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	/*
	if(a.fi != b.fi) return a.fi > b.fi;
	return dpt[a.se] < dpt[b.se];
	*/
	return (d[a.se] - dpt[a.se]) > (d[b.se] - dpt[b.se]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	rep(i, n) d1[i] = {0LL, 0LL};
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1, 0LL);
	vector<pair<ll, ll>> bst;
	rep(i, n) bst.pb(mp(d[i], i));
	sort(all(bst), cmp);
	ll ans = 0LL;
	vector<ll> cnt;
	rep(i, n - k) t[bst[i].se] = 1LL, cnt.pb(bst[i].se); 
	dfs1(0, -1);
	rep(i, cnt.size()) ans += (ll)(d1[cnt[i]].fi - d1[cnt[i]].se);
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
