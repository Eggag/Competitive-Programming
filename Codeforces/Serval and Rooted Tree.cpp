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

int a[300005], dp[300005];
vi g[300005];

void dfs(int u){
	if(!g[u].size()) dp[u] = 1;
	else{
		for(int c : g[u]) dfs(c);
		if(!a[u]){
			dp[u] = 0;
			for(int v : g[u]){
				dp[u] += dp[v];
			}
		}
		else{
			dp[u] = dp[g[u][0]];
			for(int x : g[u]){
				dp[u] = min(dp[u], dp[x]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	repn(i, 1, n + 1) cin >> a[i];
	repn(i, 2, n + 1){
		int x;
		cin >> x;
		g[x].pb(i);
	}
	int le = 0;
	repn(i, 1, n + 1){
		if(!g[i].size()) le++;
	}
	repn(i, 1, n + 1) dp[i] = 1e9;
	dfs(1);
	cout << le - dp[1] + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
