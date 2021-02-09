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
#define inf 0x3f3f3f3f
const int mxN = 3005;
const int logn = 13;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll h[mxN][mxN], r[mxN][mxN];
ll g[mxN * mxN];
ll mn[14][mxN];

ll minQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return min(mn[t][l], mn[t][r - (1 << t)]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	ll x, y, z;
	cin >> g[0] >> x >> y >> z;
	repn(i, 1, mxN * mxN) g[i] = (g[i - 1] * x + y) % z;
	rep(i, n) rep(j, m) h[i][j] = g[(i * m) + j];
	rep(j, m){
		memset(mn, inf, sizeof(mn));
		rep(i, n) mn[0][i] = h[i][j];
		for(int l = 0; l < logn - 1; l++){
			for(int k = 0; k + (2 << l) <= n; k++){
				mn[l + 1][k] = min(mn[l][k], mn[l][k + (1 << l)]);
			}
		}
		rep(i, n - a + 1) r[j][i] = minQ(i, i + a);
	}
	ll ans = 0LL;
	rep(i, n - a + 1){
		memset(mn, inf, sizeof(mn));
		rep(j, m) mn[0][j] = r[j][i];
		for(int l = 0; l < logn - 1; l++){
			for(int k = 0; k + (2 << l) <= m; k++){
				mn[l + 1][k] = min(mn[l][k], mn[l][k + (1 << l)]);
			}
		}
		rep(j, m - b + 1) ans += minQ(j, j + b);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
