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
const int mxN = 55;
const int mxM = 2e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[mxN][mxM], p[mxN][mxM], dp[mxN][mxM];
int suf[mxN][mxM], pref[mxN][mxM];

int s[4 * mxM], s1[4 * mxM], lazy[4 * mxM];

void down(int id, int l, int r){
	if(lazy[id]){
		s[id] += lazy[id] * (r - l);
		s1[id] += lazy[id];
		if((r - l) > 1){
			lazy[id << 1] += lazy[id];
			lazy[(id << 1) + 1] += lazy[id];
		}
	}
	lazy[id] = 0;
}
 
void increase(int x, int y, int u, int id = 1, int l = 0, int r = mxM - 1){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] += u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, (id << 1) + 1, mid, r);
	s[id] = s[id << 1] + s[(id << 1) + 1];
	s1[id] = max(s1[id << 1], s1[(id << 1) + 1]);
}
 
int maxQ(int x, int y, int id = 1, int l = 0, int r = mxM - 1){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return max(maxQ(x, y, id * 2, l, mid), maxQ(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	rep(i, n) rep(j, m) cin >> g[i][j];
	rep(i, n){
		p[i][0] = g[i][0];
		repn(j, 1, m) p[i][j] = p[i][j - 1] + g[i][j];
	}
	if(n == 1){
		int mx = 0;
		repn(i, k - 1, m) mx = max(mx, p[0][i] - (i - k >= 0 ? p[0][i - k] : 0));
		cout << mx << '\n';
		return 0;
	}
	rep(i, m - k + 1){
		dp[0][i] = p[0][i + k - 1] - (i > 0 ? p[0][i - 1] : 0);
		dp[0][i] += p[1][i + k - 1] - (i > 0 ? p[1][i - 1] : 0);
	}
	pref[0][0] = dp[0][0];
	repn(i, 1, m) pref[0][i] = max(pref[0][i - 1], dp[0][i]);
	suf[0][m - 1] = dp[0][m - 1];
	for(int i = m - 2; i >= 0; i--) suf[0][i] = max(suf[0][i + 1], dp[0][i]);
	repn(i, 1, n){
		if(i < (n - 1)){
			vi l(m + 1, 0), r(m + 1, 0);
			memset(s, 0, sizeof(s));
			memset(s1, 0, sizeof(s1));
			memset(lazy, 0, sizeof(lazy));
			rep(j, m - k + 1){
				int sum1 = p[i][j + k - 1] - (j > 0 ? p[i][j - 1] : 0);
				int sum = dp[i - 1][j] - sum1;
				increase(j, j + 1, sum);
				if(j > 0) increase(max(0, j - k + 1), j, g[i][j - 1]);
				l[j] = maxQ(max(0, j - k + 1), j + 1);
			}
			memset(s, 0, sizeof(s));
			memset(s1, 0, sizeof(s1));
			memset(lazy, 0, sizeof(lazy));
			for(int j = m - k; j >= 0; j--){
				int sum1 = p[i][j + k - 1] - (j > 0 ? p[i][j - 1] : 0);
				int sum = dp[i - 1][j] - sum1;
				increase(j, j + 1, sum);
				if(j != m - k) increase(j + 1, min(m + 1, j + k), g[i][j + k]);
				r[j] = maxQ(j, j + k);
			}
			rep(j, m - k + 1){
				int sum = p[i][j + k - 1] - (j > 0 ? p[i][j - 1] : 0);
				int sum1 = p[i + 1][j + k - 1] - (j > 0 ? p[i + 1][j - 1] : 0);
				dp[i][j] = (sum + sum1) + max(pref[i - 1][j - k], suf[i - 1][j + k]);
				dp[i][j] = max(dp[i][j], (sum + sum1) + max(l[j], r[j]));
			}
		}
		else{
			vi l(m + 1, 0), r(m + 1, 0);
			memset(s, 0, sizeof(s));
			memset(s1, 0, sizeof(s1));
			memset(lazy, 0, sizeof(lazy));
			rep(j, m - k + 1){
				int sum1 = p[i][j + k - 1] - (j > 0 ? p[i][j - 1] : 0);
				int sum = dp[i - 1][j] - sum1;
				increase(j, j + 1, sum);
				if(j > 0) increase(max(0, j - k + 1), j, g[i][j - 1]);
				l[j] = maxQ(max(0, j - k + 1), j + 1);
			}
			memset(s, 0, sizeof(s));
			memset(s1, 0, sizeof(s1));
			memset(lazy, 0, sizeof(lazy));
			for(int j = m - k; j >= 0; j--){
				int sum1 = p[i][j + k - 1] - (j > 0 ? p[i][j - 1] : 0);
				int sum = dp[i - 1][j] - sum1;
				increase(j, j + 1, sum);
				if(j != m - k) increase(j + 1, min(m + 1, j + k), g[i][j + k]);
				r[j] = maxQ(j, j + k);
			}
			rep(j, m - k + 1){
				int sum = p[i][j + k - 1] - (j > 0 ? p[i][j - 1] : 0);
				int sum1 = p[i + 1][j + k - 1] - (j > 0 ? p[i + 1][j - 1] : 0);
				dp[i][j] = (sum) + max(pref[i - 1][j - k], suf[i - 1][j + k]);
				dp[i][j] = max(dp[i][j], (sum) + max(l[j], r[j]));
			}
		}
		pref[i][0] = dp[i][0];
		repn(j, 1, m) pref[i][j] = max(pref[i][j - 1], dp[i][j]);
		suf[i][m - 1] = dp[i][m - 1];
		for(int j = m - 2; j >= 0; j--) suf[i][j] = max(suf[i][j + 1], dp[i][j]);
	}
	int ans = 0;
	rep(j, m) ans = max(ans, dp[n - 1][j]);
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
