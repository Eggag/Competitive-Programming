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
const int mxN = 705;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[2][mxN][mxN];
int g[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi b = {a[0]};
	repn(i, 1, n) if(a[i] != a[i - 1]) b.pb(a[i]);
	n = (int)(b.size());
	rep(i, n) rep(j, n) g[i][j] = gcd(b[i], b[j]);
	rep(len, n){
		rep(i, n - len){
			repn(j, i, i + len + 1){
				if(!dp[0][i][i + len] && i){
					if((j <= i || dp[1][i][j - 1]) && ((j + 1) > (i + len) || dp[0][j + 1][i + len])){
						if(g[j][i - 1] > 1) dp[0][i][i + len] = 1;
					}
				}
				if(!dp[1][i][i + len] && (i + len + 1) < n){
					if((j <= i || dp[1][i][j - 1]) && ((j + 1) > (i + len) || dp[0][j + 1][i + len])){
						if(g[j][i + len + 1] > 1) dp[1][i][i + len] = 1;
					}
				}
				if(dp[0][i][i + len] && dp[1][i][i + len]) break;
			}
		}
	}
	int f = 0;
	repn(i, 1, n - 1) if(dp[1][0][i - 1] && dp[0][i + 1][n - 1]) f = 1;
	if(dp[0][1][n - 1] || dp[0][0][n - 2]) f = 1;
	cout << (f ? "Yes" : "No") << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
