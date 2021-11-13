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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[505][mxN];

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), cnt(n);
	rep(i, n) cin >> a[i];
	cnt[0] = a[0];
	repn(i, 1, n) cnt[i] = cnt[i - 1] + a[i];
	int k = 0;
	for(int i = 0; (i * (i + 1)) / 2 <= n; i++) rep(j, n){
		dp[i][j] = 0LL;
		k = i;
	}
	for(int i = n - 1; i >= 0; i--){
		if(i < (n - 1)) rep(j, k + 1) dp[j][i] = dp[j][i + 1];
		repn(j, 1, k + 1) if(i + (j - 1) < n){
			ll sm = cnt[i + (j - 1)] - (i ? cnt[i - 1] : 0LL);
			if(j == 1) dp[j][i] = max(dp[j][i], sm);
			else{
				if((i + j) < n && dp[j - 1][i + j] > sm) dp[j][i] = max(dp[j][i], sm);
			}
		}
	}
	int ans = 0;
	repn(i, 1, k + 1) rep(j, n) if(dp[i][j]) ans = max(ans, i);
	cout << ans << '\n';
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
