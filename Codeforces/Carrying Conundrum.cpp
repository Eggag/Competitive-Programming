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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[15][2][2];

void solve(){
	int n;
	cin >> n;
	string s = to_string(n);
	int m = (int)(s.size());
	memset(dp, 0, sizeof(dp));
	dp[m][0][0] = 1;
	for(int i = m - 1; i >= 0; i--){
		rep(l, 2) rep(h, 2) if(dp[i + 1][l][h]){
			rep(j, 10) rep(k, 10) if(((j + k + l) % 10) == (s[i] - '0')){
				dp[i][h][(j + k + l) >= 10] += dp[i + 1][l][h];
			}
		}
	}
	cout << dp[0][0][0] - 2 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
