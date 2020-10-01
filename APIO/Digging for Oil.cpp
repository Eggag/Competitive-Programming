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
const int mxN = 1505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, k;
int g[mxN][mxN], g1[mxN][mxN];

struct seg{
	int mx[(1 << 13)];
	int sz;
	seg(int s){
		sz = s;
		rep(i, (1 << 13)) mx[i] = -1e9;
	}
	void update(int p, int value){
		for(mx[p += sz] = value; p > 1; p >>= 1) mx[p >> 1] = max(mx[p], mx[p ^ 1]);
	}
	int query(int l, int r){
		r++;
		int res = -1e9;
		for(l += sz, r += sz; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = max(res, mx[l++]);
			if(r & 1) res = max(res, mx[--r]);
		}
		return res;
	}
};

int pref[mxN][mxN];
int dp[mxN][3];

int sum(int i, int j){
	return (pref[i + k - 1][j + k - 1] - (j ? pref[i + k - 1][j - 1] : 0) - (i ? pref[i - 1][j + k - 1] : 0) + ((i && j) ? pref[i - 1][j - 1] : 0));
}

int solve(){
	rep(i, n) rep(j, m) pref[i][j] = g[i][j];
	rep(i, n) repn(j, 1, m) pref[i][j] += pref[i][j - 1];
	rep(j, m) repn(i, 1, n) pref[i][j] += pref[i - 1][j];
	memset(dp, 0, sizeof(dp));
	int bst0 = 0, bst1 = 0;
	int ret = 0;
	rep(j, m){
		if(j >= k){
			bst0 = max(bst0, dp[j - k][0]);
			bst1 = max(bst1, dp[j - k][1]);
		}
		rep(i, n) if((n - i) >= k && (m - j) >= k){
			int cr = sum(i, j);
			dp[j][2] = max(dp[j][2], cr + bst1);
			ret = max(ret, dp[j][2]);
			dp[j][1] = max(dp[j][1], cr + bst0);
			dp[j][0] = max(dp[j][0], cr);
		}
	}
	return ret;
}

int top[mxN];
int sto[mxN][mxN];
int ans = 0;

void go(){
	seg tree(n);
	vi ma(m + 1, 0);
	memset(top, 0, sizeof(top));
	for(int j = m - 1; j >= 0; j--){
		ma[j] = ma[j + 1];
		rep(i, n) if((n - i) >= k && (m - j) >= k){
			int cr = sum(i, j);
			ma[j] = max(ma[j], cr);
		}
	}
	rep(j, m){
		rep(i, n) if((n - i) >= k && (m - j) >= k){
			int cr = sum(i, j);
			if(cr > top[i]) top[i] = cr, tree.update(i, cr);
			int tl = i - k, tr = i + k;
			int res = max((tl >= 0 ? tree.query(0, tl) : (int)-1e9), (tr <= (n - 1) ? tree.query(tr, n - 1) : (int)-1e9));
			int ret = ma[j + k] + cr + res;
			ans = max(ans, ret);
		}
	}
	memset(top, 0, sizeof(top));
	rep(i, (1 << 13)) tree.mx[i] = -1e9;
	rep(i, n) rep(j, m) g1[i][j] = g[i][m - 1 - j];
	swap(g, g1);
	rep(i, n) rep(j, m) pref[i][j] = g[i][j];
	rep(i, n) repn(j, 1, m) pref[i][j] += pref[i][j - 1];
	rep(j, m) repn(i, 1, n) pref[i][j] += pref[i - 1][j];
	rep(j, m + 1) ma[j] = 0;
	for(int j = m - 1; j >= 0; j--){
		ma[j] = ma[j + 1];
		rep(i, n) if((n - i) >= k && (m - j) >= k){
			int cr = sum(i, j);
			ma[j] = max(ma[j], cr);
		}
	}
	rep(j, m){
		rep(i, n) if((n - i) >= k && (m - j) >= k){
			int cr = sum(i, j);
			if(cr > top[i]) top[i] = cr, tree.update(i, cr);
			int tl = i - k, tr = i + k;
			int res = max((tl >= 0 ? tree.query(0, tl) : (int)-1e9), (tr <= (n - 1) ? tree.query(tr, n - 1) : (int)-1e9));
			int ret = ma[j + k] + cr + res;
			ans = max(ans, ret);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("large-6.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, n) rep(j, m) cin >> g[i][j];
	ans = solve();
	rep(i, n) rep(j, m) g1[m - j - 1][i] = g[i][j];
	swap(g, g1);
	swap(n, m);
	ans = max(ans, solve());
	go();
	rep(i, n) rep(j, m) g1[m - j - 1][i] = g[i][j];
	swap(g, g1);
	swap(n, m);
	rep(i, n) rep(j, m) pref[i][j] = g[i][j];
	rep(i, n) repn(j, 1, m) pref[i][j] += pref[i][j - 1];
	rep(j, m) repn(i, 1, n) pref[i][j] += pref[i - 1][j];
	go();
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
