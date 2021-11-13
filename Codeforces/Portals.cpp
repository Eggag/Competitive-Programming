#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
#define inf 0x3f3f3f3f
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][mxN];
vi g[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	rep(i, mxN) rep(j, mxN) dp[i][j] = -inf;
	vector<array<int, 3>> p(n + 1);
	repn(i, 1, n + 1) cin >> p[i][0] >> p[i][1] >> p[i][2];
	vi ind(n + 1);
	rep(i, n + 1) ind[i] = i;
	rep(i, m){
		int u, v;
		cin >> u >> v;
		ind[v] = max(ind[v], u);
	}
	repn(i, 1, n + 1) g[ind[i]].pb(p[i][2]);
	repn(i, 1, n + 1){
		sort(all(g[i]));
		reverse(all(g[i]));
		repn(j, 1, g[i].size()) g[i][j] += g[i][j - 1];
	}
	dp[0][k] = 0;
	repn(i, 1, n + 1){
		rep(j, mxN) if(dp[i - 1][j] >= 0 && j >= p[i][0]){
			dp[i][j + p[i][1]] = max(dp[i][j + p[i][1]], dp[i - 1][j]);
			rep(l, g[i].size()){
				int nxt = j + p[i][1] - (l + 1);
				if(nxt < 0) break;
				dp[i][nxt] = max(dp[i][nxt], dp[i - 1][j] + g[i][l]);
			}
		}
	}
	int ans = -inf;
	rep(j, mxN) ans = max(ans, dp[n][j]);
	cout << (ans < 0 ? -1 : ans) << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
