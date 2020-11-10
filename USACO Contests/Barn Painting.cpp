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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
int col[mxN];
ll dp[mxN][4];
vi g[mxN];

void dfs(int cur, int prev){
	int cnt = 0;
	if(col[cur]) dp[cur][col[cur]] = 1;
	else dp[cur][1] = dp[cur][2] = dp[cur][3] = 1;
	for(int u : g[cur]) if(u != prev){
		dfs(u, cur);
		if(!col[cur]){
			(dp[cur][1] *= (dp[u][2] + dp[u][3]) % MOD) %= MOD;
			(dp[cur][2] *= (dp[u][1] + dp[u][3]) % MOD) %= MOD;
			(dp[cur][3] *= (dp[u][2] + dp[u][1]) % MOD) %= MOD;
		}
		else if(col[cur] == 1){
			(dp[cur][1] *= (dp[u][2] + dp[u][3]) % MOD) %= MOD;
		}
		else if(col[cur] == 2){
			(dp[cur][2] *= (dp[u][1] + dp[u][3]) % MOD) %= MOD;
		}
		else{
			(dp[cur][3] *= (dp[u][2] + dp[u][1]) % MOD) %= MOD;
		}
		cnt++;
	}
	for(int u : g[cur]) if(u != prev){
		if(col[u]) dp[cur][col[u]] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
	cin >> n >> k;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i, k){
		int b, c;
		cin >> b >> c;
		col[b - 1] = c;
	}
	dfs(0, -1);
	cout << (dp[0][1] + dp[0][2] + dp[0][3]) % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
