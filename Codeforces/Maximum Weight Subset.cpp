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
const int mxN = 205;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
vi g[mxN];
int a[mxN];
int dp[mxN][mxN]; //{node, last picked}
int cnt[mxN][mxN];

void dfs(int cur, int prev){
	int bst = a[cur];
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		int mx = 0;
		rep(i, n){
			if(i >= k) mx = max(mx, dp[x][i]);
		}
		bst += mx;
	}
	repn(i, 1, n){
		if(i * 2 > k){
			for(int x : g[cur]) if(x != prev){
				dp[cur][i] += cnt[x][i - 1];
			}	
		}
		else{
			int tot = 0;
			int r = (k + 1) - i - 1;
			for(int x : g[cur]) if(x != prev){
				tot += cnt[x][r];
			}	
			for(int x : g[cur]) if(x != prev){
				tot -= cnt[x][r];
				tot += dp[x][i - 1];
				dp[cur][i] = max(dp[cur][i], tot);
				tot += cnt[x][r];
				tot -= dp[x][i - 1];
			}	
		}
	}
	dp[cur][0] = bst;
	for(int i = n; i >= 0; i--) cnt[cur][i] = max(cnt[cur][i + 1], dp[cur][i]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n) cin >> a[i];
	rep(i, n - 1){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0, -1);
	int ans = 0;
	rep(i, n) rep(j, n) ans = max(ans, dp[i][j]);
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
