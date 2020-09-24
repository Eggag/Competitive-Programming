#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
vi g[200005];
ll dp[200005];
ll ans[200005];
ll sum = 0;

void dfs(int c, int p){
	dp[c] = 1;
	for(int u : g[c]) if(u != p){
		dfs(u, c);
		dp[c] += dp[u];
	}
	sum += dp[c];
}

void dfs1(int c, int p){
	for(int v : g[c]) if(v != p){
		ans[v] = ans[c] - dp[v] + (n - dp[v]);
		dfs1(v, c);
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	ans[0] = sum;
	dfs1(0, -1);
	ll ret = 0;
	rep(i, n) ret = max(ret, ans[i]);
	cout << ret << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
