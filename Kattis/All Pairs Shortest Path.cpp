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
const int INF = 1e9;

int dp[200][200];

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	if(!n && !m && !q) exit(0);
	rep(i, 200) rep(j, 200) dp[i][j] = (i == j ? 0 : INF);
	rep(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		dp[a][b] = min(c, dp[a][b]);
	}
	rep(k, n) rep(i, n) rep(j, n){
		if(dp[i][k] < INF && dp[k][j] < INF){
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		}
	}
	rep(i, n) rep(j, n) rep(k, n){
		if(dp[k][k] < 0 && dp[i][k] != INF && dp[k][j] != INF){
			dp[i][j] = -INF;
			break;
		}
	}
	rep(i, q){
		int u, v;
		cin >> u >> v;
		if(dp[u][v] == INF) cout << "Impossible" << endl;
		else if(dp[u][v] == -INF) cout << "-Infinity" << endl;
		else cout << dp[u][v] << endl;
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	while(1) solve();	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
