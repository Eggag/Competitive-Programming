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
const int mxN = 2005;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
ll w;
ll a[mxN][mxN];
ll dp[mxN][mxN], dp1[mxN][mxN];

bool valid(int i, int j){
	return (min(i, j) >= 0 && i < n && j < m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> w;
	rep(i, n) rep(j, m) cin >> a[i][j];
	rep(i, n) rep(j, m) dp[i][j] = 1e18, dp1[i][j] = 1e18;
	ll mn = 1e18, mn1 = 1e18;
	set<pair<ll, pi>> q;
	dp[0][0] = 0LL;
	q.insert(mp(0LL, mp(0, 0)));
	ll ans = 1e18;
	while(!q.empty()){
		pair<ll, pi> cr = *q.begin();
		q.erase(q.begin());
		rep(i, 4){
			int x = cr.se.fi + dx[i], y = cr.se.se + dy[i];
			if(valid(x, y) && dp[x][y] > cr.fi + w && a[x][y] != -1){
				q.erase(mp(dp[x][y], mp(x, y)));
				dp[x][y] = cr.fi + w;
				q.insert(mp(dp[x][y], mp(x, y)));
			}
		}
	}
	rep(i, n) rep(j, m) if(dp[i][j] < 1e18 && a[i][j] > 0) mn = min(mn, dp[i][j] + a[i][j]);
	ans = min(ans, dp[n - 1][m - 1]);
	dp1[n - 1][m - 1] = 0LL;
	q.insert(mp(0LL, mp(n - 1, m - 1)));
	while(!q.empty()){
		pair<ll, pi> cr = *q.begin();
		q.erase(q.begin());
		rep(i, 4){
			int x = cr.se.fi + dx[i], y = cr.se.se + dy[i];
			if(valid(x, y) && dp1[x][y] > cr.fi + w && a[x][y] != -1){
				q.erase(mp(dp1[x][y], mp(x, y)));
				dp1[x][y] = cr.fi + w;
				q.insert(mp(dp1[x][y], mp(x, y)));
			}
		}
	}
	rep(i, n) rep(j, m) if(dp1[i][j] < 1e18 && a[i][j] > 0) mn1 = min(mn1, dp1[i][j] + a[i][j]);
	ans = min(ans, mn + mn1);
	cout << (ans < 1e18 ? ans : -1) << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
