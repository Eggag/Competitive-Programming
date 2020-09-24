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

int dp[405][405]; //the min. cost of getting [a][b]

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, ma, mb;
	cin >> n >> ma >> mb;
	rep(i, 405) rep(j, 405) dp[i][j] = 1e9;
	dp[0][0] = 0;
	vi a(n), b(n), c(n);
	int sumA = 0, sumB = 0;
	rep(i, n) cin >> a[i] >> b[i] >> c[i], sumA += a[i], sumB += b[i];
	rep(i, n){
		for(int j = sumA - a[i]; j >= 0; j--){
			for(int k = sumB - b[i]; k >= 0; k--){
				dp[j + a[i]][k + b[i]] = min(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
			}
		}
	}
	int ans = 1e9;
	repn(i, 1, sumA + 1) repn(j, 1, sumB + 1){
		int i1 = i, j1 = j;
		int g = gcd(i, j);
		i1 /= g, j1 /= g;
		if(i1 == ma && j1 == mb) ans = min(ans, dp[i][j]);
	}
	if(ans == 1e9) ans = -1;
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
