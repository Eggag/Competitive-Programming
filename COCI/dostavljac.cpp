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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
int a[mxN];
int dp[mxN][mxN][2][2]; // [node][time spent] store max sum
int lst[mxN];
int lst1[mxN][2];
vi g[mxN];

void chmax(int &a, int b){
	a = max(a, b);	
}

void dfs(int cur, int prev){
	for(int u : g[cur]) if(u != prev) dfs(u, cur);
	rep(i, m + 1) lst[i] = dp[cur][i][1][1];
	for(int u : g[cur]) if(u != prev){
		rep(i, m + 1){
			for(int j = m - (i + 2); j >= 0; j--){
				chmax(dp[cur][j + (i + 2)][1][1], lst[j] + dp[u][i][1][1]);
			}
		}
		rep(i, m + 1) lst[i] = dp[cur][i][1][1];
	}
	rep(i, m + 1){
		lst1[i][0] = dp[cur][i][0][0];
		lst1[i][1] = dp[cur][i][0][1];
	}
	for(int u : g[cur]) if(u != prev){
		rep(i, m + 1){
			for(int j = m - (i + 1); j >= 0; j--){
				if(j + (i + 2) <= m){
					//keep the states
					chmax(dp[cur][j + (i + 2)][0][0], lst1[j][0] + dp[u][i][1][1]);
					chmax(dp[cur][j + (i + 2)][0][1], lst1[j][1] + dp[u][i][1][1]);
				}
				//try the transition
				chmax(dp[cur][j + (i + 1)][0][1], lst1[j][0] + dp[u][i][0][1]);
			}
		}
		rep(i, m + 1){
			lst1[i][0] = dp[cur][i][0][0];
			lst1[i][1] = dp[cur][i][0][1];
		}
	}
	for(int i = m - 1; i >= 0; i--) rep(j, 2) rep(k, 2) chmax(dp[cur][i + 1][j][k], dp[cur][i][j][k] + a[cur]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0, -1);
	int ans = 0;
	rep(k, 2) rep(l, 2) ans = max(ans, dp[0][m][k][l]);
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
