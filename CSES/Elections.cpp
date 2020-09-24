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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pair<vi, int> dp[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	int tot = 0;
	rep(i, n) cin >> a[i], tot += a[i];
	rep(i, mxN) dp[i].se = -1e9;
	dp[0].se = 1e9;
	rep(i, n){
		for(int j = 100000 - a[i]; j >= 0; j--){
			if((min(dp[j].se, a[i]) > dp[j + a[i]].se || (dp[j + a[i]].se == -1e9)) && (!j || dp[j].fi.size()) && (j + a[i] - min(dp[j].se, a[i])) <= (tot / 2)){
				dp[j + a[i]].fi = dp[j].fi;
				dp[j + a[i]].fi.pb(i + 1);
				if(dp[j + a[i]].se != -1e9) dp[j + a[i]].se = min(a[i], dp[j].se);
				else dp[j + a[i]].se = min(a[i], dp[j].se);
			}
		}
	}
	for(int i = mxN - 1; i > (tot / 2); i--){
		if(dp[i].fi.size()){
			cout << dp[i].fi.size() << endl;
			rep(j, dp[i].fi.size()) cout << dp[i].fi[j] << " ";
			cout << endl;
			return 0;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
