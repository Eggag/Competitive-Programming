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
const int MOD = 1e9 + 7;

ll dp[100005][2];
vi g[100005];
//0 if the edge is black and 1 if it is white

void dfs(int c, int p){
	dp[c][0] = dp[c][1] = 1;
	for(int u : g[c]) if(u != p){
		dfs(u, c);
		//if it is white, the next one could be either color
		//if it is black, the next one could only be white
		dp[c][0] = (dp[c][0] * dp[u][1]) % MOD;
		dp[c][1] = (dp[c][1] * (dp[u][0] + dp[u][1])) % MOD;
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
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	cout << (dp[0][0] + dp[0][1]) % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
