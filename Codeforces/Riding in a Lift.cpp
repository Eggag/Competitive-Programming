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
const int mxN = 5005;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[2][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	dp[0][a] = 1LL;
	repn(i, 1, k + 1){
		int cr = i & 1, pr = 1 - cr;
		vector<ll> upd(n + 2, 0);
		repn(j, 1, n + 1) if(j != b){
			//we update from this one
			int d = abs(j - b);
			if(d > 1){
				int l = j - (d - 1), r = j + (d - 1);
				l = max(l, 1), r = min(r, n);
				(upd[l] += dp[pr][j]) %= MOD;
				(upd[r + 1] += (MOD - dp[pr][j])) %= MOD;
				(upd[j] += (MOD - dp[pr][j])) %= MOD;
				(upd[j + 1] += dp[pr][j]) %= MOD;
			}
		}
		repn(j, 1, n + 1) (upd[j] += upd[j - 1]) %= MOD;
		repn(j, 1, n + 1){
			(dp[cr][j] += upd[j]) %= MOD;
		}
		repn(j, 1, n + 1) dp[pr][j] = 0;
	}
	ll tot = 0;
	repn(i, 1, n + 1) (tot += dp[k & 1][i]) %= MOD;
	cout << tot << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
