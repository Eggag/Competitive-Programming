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

int n, m;
int rt, pos = 0;
int a[mxN], inv[mxN], st[mxN], nxt[mxN];
int dp[mxN][505];
vi g[mxN];

void chmax(int &a, int b){
	a = max(a, b);
}

void dfs(int cur){
	st[cur] = pos++;
	inv[pos - 1] = cur;
	for(int u : g[cur]) dfs(u);
	nxt[st[cur]] = pos;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n){
		int p;
		cin >> p >> a[i];
		p--;
		if(~p) g[p].pb(i);
		else rt = i;
	}
	dfs(rt);
	memset(dp, -1, sizeof(dp));
	rep(i, mxN) dp[i][0] = 0;
	rep(k, n){
		int i = inv[k];
		rep(j, m + 1){
			//we are updating from dp[i][j]
			if(~dp[k][j]) chmax(dp[k + 1][j], dp[k][j]);
			if(j < m && ~dp[k][j]) chmax(dp[nxt[k]][j + 1], dp[k][j] + a[i]);
		}
	}
	int ans = 0;
	rep(i, n + 1) ans = max(ans, dp[i][m]);
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
