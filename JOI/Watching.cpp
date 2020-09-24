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
const int mxN = 2005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, p, q;
int a[mxN], nxt[mxN], nxt1[mxN];
pi dp[mxN][mxN];

bool check(int w){
	rep(i, mxN) rep(j, mxN) dp[i][j] = mp(0, 1e9);
	dp[0][0] = {1, 0};
	rep(i, n){
		nxt[i] = ub(a, a + n, a[i] + w - 1) - a;
		nxt1[i] = ub(a, a + n, a[i] + (2 * w) - 1) - a;
	}
	rep(i, n){
		rep(j, p + 1) if(dp[i][j].fi){
			if(j < p){
				dp[nxt[i]][j + 1].fi = 1;
				dp[nxt[i]][j + 1].se = min(dp[i][j].se, dp[nxt[i]][j + 1].se);
			}
			dp[nxt1[i]][j].fi = 1;
			dp[nxt1[i]][j].se = min(dp[i][j].se + 1, dp[nxt1[i]][j].se);
		}
	}
	rep(i, p + 1) if(dp[n][i].fi && dp[n][i].se <= q) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> p >> q;
	p = min(p, 2000), q = min(q, 2000);
	rep(i, n) cin >> a[i];
	sort(a, a + n);
	int l = 1, r = 1e9;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
