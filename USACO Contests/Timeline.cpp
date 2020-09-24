#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, c;
int dp[100005];
int s[100005];
int deg[100005];
vector<pi> g[100005];

int calculate(int num){
	if(dp[num]) return dp[num];
	int ans = s[num];
	for(pi v : g[num]){
		ans = max(ans, calculate(v.fi) + v.se);
	}
	return (dp[num] = ans);
}

int vis1[100005]; //don't forget to initialize to zeroes
vi ord; //don't forget to reverse in the end
 
void dfs0(int cur){
	vis1[cur] = 1;
	for(pi x : g[cur]) if(!vis1[x.fi]) dfs0(x.fi);
	ord.pb(cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);
	cin >> n >> m >> c;
	rep(i, n) cin >> s[i];
	memset(deg, 0, sizeof(deg));
	memset(dp, 0, sizeof(dp));
	rep(i, c){
		int a, b, x;
		cin >> a >> b >> x;
		a--, b--;
		g[b].pb(mp(a, x));
		deg[b]++;
	}
	memset(vis1, 0, sizeof(vis1));
	rep(i, n) if(!vis1[i]) dfs0(i);
	reverse(all(ord));
	rep(i, n) dp[ord[i]] = calculate(ord[i]);
	rep(i, n) cout << dp[i] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
