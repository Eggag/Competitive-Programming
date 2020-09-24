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

const int maxn = 100005;

vi g[maxn];
int dp[maxn];
int in[maxn];

int dfs(int cur){
	if(!dp[cur]){
		for(int v : g[cur]){
			dp[cur] = max(dfs(v) + 1, dp[cur]);
		}
	}
	return dp[cur];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		in[b]++;
	}
	int ans = 0;
	rep(i, n) if(!in[i]){
		ans = max(ans, dfs(i));
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
