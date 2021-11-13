#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define debug(x) cerr << #x << " " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) v.begin, v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define inf 0x3f3f3f3f
const int mxN = 1e5 + 5;

int n;
int c[mxN];
int dp[mxN][2][2];
vi g[mxN];

void dfs(int cur, int prev){
	//dp[node][type: 0 for all 0s, 1 for 1 at root, the rest 0s][flipped]
	int cnt = 0;
	for(int x : g[cur]) if(x != prev){
		cnt++;
		dfs(x, cur);
	}
	if(!cnt){
		if(c[cur]){
			dp[cur][1][0] = 0;
			dp[cur][0][1] = 1;
		}
		else{
			dp[cur][1][1] = 1;
			dp[cur][0][0] = 0;
		}
		return;
	}
	vector<vi> v(2, {0, 0});
	int nm = 0, cst = 0;
	for(int x : g[cur]) if(x != prev){
		if(dp[x][0][0] < dp[x][0][1]){
			cst += dp[x][0][0];
			cst = min(cst, inf);
		}
		else{
			cst += dp[x][0][1];
			cst = min(cst, inf);
			nm++;
		}
	}
	int mn = inf;
	for(int x : g[cur]) if(x != prev){
		if(dp[x][0][0] < dp[x][0][1]){
			mn = min(mn, dp[x][0][1] - dp[x][0][0]);
		}
		else{
			mn = min(mn, dp[x][0][0] - dp[x][0][1]);
		}
	}
	if(nm & 1){
		v[0][1] = cst;
		v[0][0] = min(inf, cst + mn);
	}
	else{
		v[0][0] = cst;
		v[0][1] = min(inf, cst + mn);
	}
	nm = 0, cst = 0;
	for(int x : g[cur]) if(x != prev){
		if(dp[x][1][0] < dp[x][1][1]){
			cst += dp[x][1][0];
			cst = min(cst, inf);
		}
		else{
			cst += dp[x][1][1];
			cst = min(cst, inf);
			nm++;
		}
	}
	mn = inf;
	for(int x : g[cur]) if(x != prev){
		if(dp[x][1][0] < dp[x][1][1]){
			mn = min(mn, dp[x][1][1] - dp[x][1][0]);
		}
		else{
			mn = min(mn, dp[x][1][0] - dp[x][1][1]);
		}
	}
	if(nm & 1){
		v[1][1] = cst;
		v[1][0] = min(inf, cst + mn);
	}
	else{
		v[1][0] = cst;
		v[1][1] = min(inf, cst + mn);
	}
	if(c[cur]){
		dp[cur][0][1] = 1 + v[1][0];
		dp[cur][0][0] = v[0][1];
	}
	else{
		dp[cur][0][1] = 1 + v[1][1];
		dp[cur][0][0] = v[0][0];
	}
	if(c[cur]){
		dp[cur][1][1] = 1 + v[1][1];
		dp[cur][1][0] = v[0][0];
	}
	else{
		dp[cur][1][1] = 1 + v[1][0];
		dp[cur][1][0] = v[0][1];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memset(dp, inf, sizeof(dp));
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i, n) cin >> c[i];
	dfs(0, -1);	
	int ans = min(dp[0][0][0], dp[0][0][1]);
	if(ans >= 1e9) cout << "impossible\n";
	else cout << ans << '\n';
}
