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
const int mxN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[2][mxN * mxN];

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	ll ans = 0;
	rep(i, n){
		cin >> a[i];
		ans += sq(a[i]) * (ll)(n - 1);
	}
	rep(i, n){
		cin >> b[i];
		ans += sq(b[i]) * (ll)(n - 1);
	}
	ll sum = a[0] + b[0];
	rep(i, 2) rep(j, mxN * n) dp[i][j] = 1e18;
	dp[0][a[0]] = 0, dp[0][b[0]] = 0;
	repn(i, 1, n){
		int cr = i & 1;
		rep(j, mxN * n) if(dp[cr ^ 1][j] < 1e18){
			ll uwu = (2 * a[i] * j) + (2 * b[i] * (sum - j));
			dp[cr][(j + a[i])] = min(dp[cr][(j + a[i])], uwu + dp[cr ^ 1][j]);
			uwu = (2 * b[i] * j) + (2 * a[i] * (sum - j));
			dp[cr][(j + b[i])] = min(dp[cr][(j + b[i])], uwu + dp[cr ^ 1][j]);
		}
		sum += (a[i] + b[i]);
		rep(j, mxN * n) dp[cr ^ 1][j] = 1e18;
	}
	ll mn = 1e18;
	rep(j, mxN * n) mn = min(mn, dp[(n - 1) & 1][j]);
	cout << mn + ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
