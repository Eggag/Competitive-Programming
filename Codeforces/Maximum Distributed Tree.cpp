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
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
vi g[mxN];
ll d[mxN];

void dfs0(int cur, int prev){
	d[cur] = 1LL;
	for(int x : g[cur]) if(x != prev){
		dfs0(x, cur);
		d[cur] += d[x];
	}
}

bool cmp(pi a, pi b){
	ll a1 = min(d[a.fi], d[a.se]) * (n - min(d[a.fi], d[a.se]));
	ll b1 = min(d[b.fi], d[b.se]) * (n - min(d[b.fi], d[b.se]));
	return a1 > b1;
}

void solve(){
	cin >> n;
	rep(i, n) d[i] = 0, g[i].clear();
	vector<pi> ed(n - 1);
	rep(i, n - 1){
		cin >> ed[i].fi >> ed[i].se;
		ed[i].fi--, ed[i].se--;
		g[ed[i].fi].pb(ed[i].se);
		g[ed[i].se].pb(ed[i].fi);
	}
	int m;
	cin >> m;
	vector<ll> p(m);
	rep(i, m) cin >> p[i];
	if(m < (n - 1)){
		rep(i, (n - 1) - m) p.pb(1LL);
		sort(all(p));
	}
	else{
		//we make the largest one larger
		int nm = m - (n - 1);
		sort(all(p));
		while(nm--){
			assert((int)p.size() >= 2);
			ll cr = p[(int)p.size() - 1], cr1 = p[(int)p.size() - 2];
			ll nm = (cr * cr1) % MOD;
			p.pop_back();
			p.pop_back();
			p.pb(nm);
		}
	}
	//now we sort the edges
	//but first we need to find the subtree sizes
	dfs0(0, -1);
	sort(all(ed), cmp);
	reverse(all(p));
	ll ans = 0LL;
	rep(i, n - 1){
		ll mn = min(d[ed[i].fi], d[ed[i].se]);
		ll cur = (p[i] * ((mn * (n - mn)) % MOD)) % MOD;
		(ans += cur) %= MOD;
	}
	cout << ans << endl;
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
