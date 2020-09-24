#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int MAXN = 100005;
const int MOD = 1e9 + 7;

vi g[MAXN];
ll dp[MAXN][2];

void dfs(int c, int p){
	dp[c][0] = dp[c][1] = 1;
	for(int u : g[c]) if(u != p){
		dfs(u, c);
		dp[c][0] = (dp[c][0] * (dp[u][1] + dp[u][0])) % MOD;
		dp[c][1] = (dp[c][1] * dp[u][0]) % MOD;;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1, 0);
	cout << (dp[1][1] + dp[1][0]) % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
