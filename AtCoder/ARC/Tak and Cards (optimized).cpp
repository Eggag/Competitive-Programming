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

ll dp[55][55][2505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, a;
	cin >> n >> a;
	vi x(n + 1);
	repn(i, 1, n + 1) cin >> x[i];
	ll ans = 0LL;
	rep(i, 55) rep(j, 55) rep(k, 2505) dp[i][j][k] = 0LL;
	dp[0][0][0] = 1LL;
	repn(j, 1, n + 1){
		rep(k, n + 1){
			rep(l, 2501) dp[j][k][l] += dp[j - 1][k][l]; //don't include it
			if(k){
				for(int l = 2500 - x[j]; l >= 0; l--){
					dp[j][k][l + x[j]] += dp[j - 1][k - 1][l];
				}
			}
		}
	}
	repn(i, 1, n + 1) ans += dp[n][i][i * a];
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
