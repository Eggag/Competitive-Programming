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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[2][40][40];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	vector<pi> comps;
	int cur = 1;
	repn(i, 1, n){
		if(a[i] == a[i - 1]) cur++;
		else{
			comps.pb(mp(a[i - 1], cur));
			cur = 1;
		}
	}
	comps.pb(mp(a[n - 1], cur));
	int m = comps.size();
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	repn(i, 1, m + 1){
		int cr = i & 1, pr = 1 - cr;
		rep(j, 39) rep(k, 39) if(~dp[pr][j][k]){
			//add to 1
			int f = 0;
			if(!j || ((i - 1) >= j && comps[(i - 1) - j].fi != comps[i - 1].fi)) f = 1;
			int k1 = k + 1 - (!k);
			dp[cr][1][k1] = max(dp[cr][1][k1], dp[pr][j][k] + f);
			f = 0;
			if(!k || ((i - 1) >= k && comps[(i - 1) - k].fi != comps[i - 1].fi)) f = 1;
			int j1 = j + 1 - (!j);
			dp[cr][j1][1] = max(dp[cr][j1][1], dp[pr][j][k] + f);
			if(comps[i - 1].se > 1){
				//we can add to both
				f = 0;
				if(!j || ((i - 1) >= j && comps[(i - 1) - j].fi != comps[i - 1].fi)) f++;
				if(!k || ((i - 1) >= k && comps[(i - 1) - k].fi != comps[i - 1].fi)) f++;
				dp[cr][1][1] = max(dp[cr][1][1], dp[pr][j][k] + f);
			}
		}
		memset(dp[pr], -1, sizeof(dp[pr]));
	}
	int ans = 0;
	rep(i, 40) rep(j, 40) ans = max(ans, dp[(m & 1)][i][j]);
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
