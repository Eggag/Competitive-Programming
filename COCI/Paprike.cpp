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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll k, h[mxN];
pair<ll, ll> dp[mxN];
vi g[mxN];

void dfs(int cur, int prev){
	vector<ll> pos;
	dp[cur] = {h[cur], 0LL};
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		dp[cur].fi += dp[x].fi;
		dp[cur].se += dp[x].se;
		pos.pb(dp[x].fi);
	}
	sort(all(pos));
	reverse(all(pos));
	rep(i, pos.size()){
		if(dp[cur].fi <= k) break;
		dp[cur].se++;
		dp[cur].fi -= pos[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n) cin >> h[i];
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(dp, 0LL, sizeof(dp));
	dfs(0, -1);
	cout << dp[0].se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
