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
vi g[mxN], sp[mxN];
ll w[mxN];
int b[mxN], vis[mxN];
ll dp[mxN][2];

void dfs0(int cur, int prev = -1){
	vis[cur] = 1;
	for(int x : g[cur]) if(x != prev){
		if(!vis[x]) sp[cur].pb(x), dfs0(x, cur);
		else b[x]++; //each has another back edge out of it
	}
}

void dfs1(int cur){
	for(int x : sp[cur]){
		dfs1(x);
		b[cur] += b[x];
	}
	dp[cur][1] = w[cur]; //we can just take this one bcuz why no
	dp[cur][0] = (b[cur] ? w[cur] : 0LL);
	ll tot = 0LL;
	for(int x : sp[cur]) dp[cur][0] += dp[x][0], tot += dp[x][0];
	for(int x : sp[cur]) dp[cur][1] = max(dp[cur][1], tot - dp[x][0] + dp[x][1] + w[cur]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> w[i];
	rep(i, m){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	int s;
	cin >> s;
	s--;
	dfs0(s);
	//now we have the dfs tree so we do dp on tree
	memset(dp, 0, sizeof(dp));
	dfs1(s);
	cout << max(dp[s][0], dp[s][1]) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
