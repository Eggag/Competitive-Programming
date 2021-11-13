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
const int mxN = 8005;
const ld eps = 1e-8;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ld dp[mxN][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int k, q;
	cin >> k >> q;
	vi p(q);
	rep(i, q) cin >> p[i];
	dp[0][0] = 1.0;
	repn(i, 1, mxN){
		rep(j, min(i, 1004)){
			ld pr = (ld)((ld)(k - j) / k);
			dp[i][j + 1] += (ld)(dp[i - 1][j] * pr);
			dp[i][j] += (ld)(dp[i - 1][j] * (1.0 - pr));
		}
	}
	rep(i, q){
		int l = 1, r = mxN - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if((ld)(2000.0 * dp[mid][k]) - eps > (ld)(p[i])) r = mid;
			else l = mid + 1;
		}
		cout << l << '\n';
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
