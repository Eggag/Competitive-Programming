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
const int mxN = 65;
const ld inf = 1e18;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int x;
pair<ld, string> dp[mxN][mxN][mxN];

void solve(){
	ld w, e;
	cin >> w >> e;
	w *= 1000000000000, e *= 1000000000000;
	rep(i, mxN) rep(j, mxN) rep(k, mxN) dp[i][j][k] = mp(-inf, "");
	dp[0][0][0] = mp(0.0, "");
	repn(i, 1, 61){
		rep(r, 60) rep(p, 60) if(i >= (r + p)){
			int s = i - (r + p);
			ld pr = 1.0 / 3.0;
			ld pp = pr, ps = pr;
			if(i > 1){
				pr = (ld)((ld)(s) / (ld)(i - 1));
				pp = (ld)((ld)(r) / (ld)(i - 1));
				ps = (ld)((ld)(p) / (ld)(i - 1));
			}
			ld s1 = dp[i - 1][r][p].fi;
			string res = dp[i - 1][r][p].se;
			ld cst = s1 + (e * pr) + (w * ps);
			if(cst > dp[i][r + 1][p].fi) dp[i][r + 1][p] = mp(cst, (string)(res + 'R'));
			cst = s1 + (e * pp) + (w * pr);
			if(cst > dp[i][r][p + 1].fi) dp[i][r][p + 1] = mp(cst, (string)(res + 'P'));
			cst = s1 + (e * ps) + (w * pp);
			if(cst > dp[i][r][p].fi) dp[i][r][p] = mp(cst, (string)(res + 'S'));
		}
	}
	ld ans = 0.0;
	string bs = "";
	rep(r, 61) rep(p, 61){
		if(dp[60][r][p].fi > ans){
			bs = dp[60][r][p].se, ans = dp[60][r][p].fi;
		}
	}
	cout << bs << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t >> x;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
