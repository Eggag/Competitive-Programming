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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pair<ll, pair<ll, ll>>> g[55];
ll dp[55][2505]; //time to get to i and have j coins

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m, s;
	cin >> n >> m >> s;
	ll mxn = 2500;
	rep(i, m){
		int u, v;
		ll a, b;
		cin >> u >> v >> a >> b;
		u--, v--;
		g[u].pb(mp(v, mp(a, b)));
		g[v].pb(mp(u, mp(a, b)));
	}
	s = min(s, (ll)mxn);
	vector<ll> c(n), d(n);
	rep(i, n) cin >> c[i] >> d[i];
	rep(i, 55) rep(j, 2505) dp[i][j] = 1e18;
	dp[0][s] = 0LL;
	set<pair<ll, pair<ll, ll>>> q;
	q.insert(mp(dp[0][s], mp(0LL, s)));
	while(!q.empty()){
		pair<ll, ll> cur = q.begin() -> se;
		q.erase(q.begin());
		for(pair<ll, pair<ll, ll>> v : g[cur.fi]){
			ll amt = cur.se;
			ll cur1 = dp[cur.fi][cur.se];
			while(amt <= mxn){
				//do the update
				if(amt >= v.se.fi && (cur1 + v.se.se) < dp[v.fi][amt - v.se.fi]){
					q.erase(mp(dp[v.fi][amt - v.se.fi], mp(v.fi, amt - v.se.fi)));
					dp[v.fi][amt - v.se.fi] = cur1 + v.se.se;
					q.insert(mp(dp[v.fi][amt - v.se.fi], mp(v.fi, amt - v.se.fi)));
				}
				amt += max(1LL, min(c[cur.fi], mxn - amt));
				cur1 += d[cur.fi];
			}	
		}
	}
	repn(i, 1, n){
		ll ans = 1e18;
		rep(j, 2505) ans = min(ans, dp[i][j]);
		cout << ans << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
