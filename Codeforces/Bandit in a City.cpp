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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll a[mxN], leaves[mxN];
pair<ll, ll> dp[mxN]; //{how much we can just put, the max}
vi g[mxN];

void dfs(int cur, int prev){
	ll mx = 0, cnt = 0;
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		leaves[cur] += leaves[x];
		mx = max(mx, dp[x].se);
		cnt++;
	}
	if(!cnt) leaves[cur] = 1;
	for(int x : g[cur]) if(x != prev){
		dp[cur].fi += dp[x].fi;
		dp[cur].fi += (ll)(leaves[x] * (mx - dp[x].se));
	}
	dp[cur].se = mx;
	ll sb = a[cur];
	if(dp[cur].fi >= sb) dp[cur].fi -= sb;
	else{
		sb -= dp[cur].fi;
		dp[cur].fi = 0LL;
		ll md = leaves[cur] - (sb % leaves[cur]);
		md %= leaves[cur];
		dp[cur].se += (sb + leaves[cur] - 1) / leaves[cur];
		dp[cur].fi = md;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	repn(i, 1, n){
		int b;
		cin >> b;
		b--;
		g[i].pb(b);
		g[b].pb(i);
	}
	rep(i, n) cin >> a[i];
	dfs(0, -1);
	cout << dp[0].se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
