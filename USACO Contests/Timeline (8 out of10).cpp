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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);
	cin >> n >> m >> c;
	vi s(n);
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
	rep(i, n) if(!deg[i]) dp[i] = s[i];
	rep(i, n) dp[i] = calculate(i);
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
