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
const int mxN = 1e3 + 5, mxM = 1e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN][mxM];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, w, b, x;
	cin >> n >> w >> b >> x;
	vector<ll> c(n + 1), cst(n + 1);
	ll mx = 0;
	repn(i, 1, n + 1) cin >> c[i];
	repn(i, 1, n + 1) cin >> cst[i];
	rep(i, mxN) rep(j, mxM) dp[i][j] = -1e18;
	dp[0][0] = w;
	repn(i, 1, n + 1){
		rep(j, mx + 1) if(dp[i - 1][j] >= 0){
			ll uwu = w + (j * b);
			ll bal = min(uwu, dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], bal + x);
			repn(k, 1, c[i] + 1){
				if(bal < cst[i]) break;
				bal -= cst[i];
				bal = min(bal, uwu);
				uwu += b;
				dp[i][j + k] = max(dp[i][j + k], bal + x);
			}
		}
		mx += c[i];
	}
	int ans = 0;
	rep(j, mxM) if(dp[n][j] >= 0) ans = j;
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
