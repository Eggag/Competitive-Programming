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
 
int n;
int dp[mxN][2];
string s;
vi g[mxN];
 
void dfs(int cur, int prev){
	if(s[cur] == '1') dp[cur][0] = 1;
	int tot = 0, mx = 0;
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		tot += dp[x][0];
		mx = max(mx, dp[x][0]);
	}
	dp[cur][0] = max(tot - (s[cur] == '1'), dp[cur][0]);
	if(s[cur] == '1') dp[cur][1] = mx + 1;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	int cnt = 0;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	cin >> s;
	rep(i, n) cnt += (s[i] == '1');
	int ans = 0, mn = 0;
	if(cnt == 2) mn = 2;
	dfs(0, -1);
	rep(i, n) ans = max({ans, dp[i][0], dp[i][1]});
	cout << max(mn, ans) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
