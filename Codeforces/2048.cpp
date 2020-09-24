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
const int mxN = 2005;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][(1 << 12)][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, K;
	cin >> n >> K;
	vi a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	dp[0][0][0] = 1;
	repn(i, 1, n + 1){
		int le = 1, ri = 3;
		if(a[i] == 2) le = 1, ri = 2;
		if(a[i] == 4) le = 2, ri = 3;
		rep(j, (1 << 12)) rep(k, 2) repn(l, le, ri) if(dp[i - 1][j][k]){
			int j1 = j;
			int lo = 0;
			rep(m, 13) if(j1 & (1 << m)){
				lo = m;
				break;
			}
			if((1 << lo) < (1 << l)) j1 = (1 << l);
			else{
				int f1 = 1;
				repn(m, l, 11){
					if((f1 + ((j1 & (1 << m)) > 0)) > 1){
						j1 ^= (1 << m);
						if(m == 10) j1 |= (1 << (m + 1));
					}
					else if(f1) j1 |= (1 << m), f1 = 0;
					else break;
				}
			}
			int f = (j1 >= (1 << K));
			dp[i][j1][(k | f)] += dp[i - 1][j][k];
			if(dp[i][j1][(k | f)] >= MOD) dp[i][j1][(k | f)] -= MOD;
		}
	}
	int ans = 0LL;
	rep(j, (1 << 12)){
		ans += dp[n][j][1];
		if(ans >= MOD) ans -= MOD;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
