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
ll a[mxN], dp[mxN], d[mxN];
int b[mxN], c[mxN];
vi g[mxN];

void dfs(int cur, int prev, ll mn = 1e18){
	ll o = 0LL, z = 0LL;
	if(!b[cur] && c[cur]) d[cur] = 1, o = 1LL;
	if(b[cur] && !c[cur]) d[cur] = -1, z = 1LL;
	a[cur] = min(a[cur], mn);
	mn = min(a[cur], mn);
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur, mn);
		d[cur] += d[x];
		dp[cur] += dp[x];
		if(d[x] > 0) o += d[x];
		else z -= d[x];
	}
	dp[cur] += a[cur] * 2 * min(o, z);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	int c01 = 0, c10 = 0;
	rep(i, n){
		cin >> a[i] >> b[i] >> c[i];
		if(!b[i] && c[i]) c01++;
		if(b[i] && !c[i]) c10++;
	}
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	if(c01 != c10){
		cout << -1 << endl;
		return 0;
	}
	dfs(0, -1);
	cout << dp[0] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
