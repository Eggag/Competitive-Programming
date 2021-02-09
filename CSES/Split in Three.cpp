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
const int mxN = 1675;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pair<int, pi> dp[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	//x - 1, x, x + 1
	int sum = (n * (n + 1)) / 2;
	if(sum % 3 != 0){
		cout << "IMPOSSIBLE" << '\n';
		return 0;
	}
	int x = sum / 3;
	rep(i, mxN) rep(j, mxN) dp[i][j] = mp(0, mp(-1, -1));
	dp[0][0] = mp(1, mp(-1, -1));
	for(int i = n; i >= 1; i--){
		if(dp[x - 1][x].fi) break;
		for(int j = x; j >= 0; j--){
			for(int k = x; k >= 0; k--) if(dp[j][k].fi){
				if(x - j >= i && !dp[j + i][k].fi){
					dp[j + i][k].fi = 1;
					dp[j + i][k].se = mp(j, k);
				}
				if(x - k >= i && !dp[j][k + i].fi){
					dp[j][k + i].fi = 1;
					dp[j][k + i].se = mp(j, k);
				}
			}
		}
	}
	if(dp[x - 1][x].fi){
		vi ans(n, 3);
		int a = x - 1, b = x;
		while(dp[a][b].se.fi != -1){
			int dif = max(a - dp[a][b].se.fi, b - dp[a][b].se.se);
			int f = 1;
			if(a == dp[a][b].se.fi) f = 0;
			ans[dif - 1] = (f ? 1 : 2);
			int a1 = dp[a][b].se.fi, b1 = dp[a][b].se.se;
			a = a1, b = b1;
		}
		rep(i, n) cout << ans[i] << " ";
		cout << '\n';
	}
	else cout << "IMPOSSIBLE" << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
