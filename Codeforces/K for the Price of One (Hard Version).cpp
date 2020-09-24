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


void solve(){
	int n, p, k;
	cin >> n >> p >> k;
	int a[n + 1];
	repn(i, 1, n + 1) cin >> a[i];
	sort(a + 1, a + n + 1);
	pi dp[n + 1][2];
	rep(i, n + 1) rep(j, 2) dp[i][j] = {0, 0};
	dp[0][0] = {1, p};
	dp[0][1] = {1, p};
	repn(i, 1, n + 1){
		int f = 1;
		if(dp[i - 1][0].se >= a[i]){
			dp[i][0].fi |= dp[i - 1][0].fi;
			dp[i][0].se = dp[i - 1][0].se - a[i];
			f = 0;
		}
		if(dp[i - 1][1].se >= a[i]){
			if(dp[i - 1][1].fi && (f || (dp[i][0].se <= (dp[i - 1][1].se - a[i])))){
				dp[i][0].fi |= dp[i - 1][1].fi;
				dp[i][0].se = dp[i - 1][1].se - a[i];
				f = 0;
			}
		}
		int f1 = 1;
		if(i >= k && dp[i - k][1].se >= a[i]){
			dp[i][1].fi |= dp[i - k][1].fi;
			dp[i][1].se = dp[i - k][1].se - a[i];
			f1 = 0;
		}
		if(i >= k && dp[i - k][0].se >= a[i]){
			if(dp[i - k][0].fi && (f1 || (dp[i][1].se <= (dp[i - k][0].se - a[i])))){
				dp[i][1].fi |= dp[i - k][0].fi;
				dp[i][1].se = dp[i - k][0].se - a[i];
			}
		}
	}
	int ans = 0;
	rep(i, n + 1){
		if(dp[i][0].fi || dp[i][1].fi) ans = i;
	}
	/*
	rep(i, n + 1){
		debug(i);
		debug2(dp[i][0].fi, dp[i][1].fi);
		debug2(dp[i][0].se, dp[i][1].se);
	}
	*/
	cout << ans << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
