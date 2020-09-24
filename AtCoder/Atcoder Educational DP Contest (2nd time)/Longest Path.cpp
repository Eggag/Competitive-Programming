#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#ifdef LOCAL
clock_t timer = clock();
#endif

vi g[100005];
int dp[100005];
int v[100005];
int ind[100005];

void dfs(int cur){
	v[cur] = 1;
	for(int u : g[cur]){
		dp[u] = max(dp[u], dp[cur] + 1);
		ind[u]--;
		if(ind[u] == 0) dfs(u);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		ind[b]++;
	}
	for(int i = 0; i < n; i++){
		if(v[i] || ind[i]) continue;
		dfs(i);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, dp[i]);
	} 
	cout << ans << endl;
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
