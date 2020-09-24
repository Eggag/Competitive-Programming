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

ld dp[2005][2005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, t;
	ld p;
	cin >> n >> p >> t;
	rep(i, 2005) rep(j, 2005) dp[i][j] = 0;
	dp[0][n] = 1;
	repn(i, 1, t + 1){
		rep(j, n + 1){
			dp[i][j] = (ld)(dp[i - 1][j] * (1 - p)) + (ld)(dp[i - 1][j + 1] * p);
		}
	}
	ld ans = 0;
	rep(i, n + 1) ans += (ld)(i * dp[t][i]);
	cout << fixed << setprecision(30) << (ld)(n - ans) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
