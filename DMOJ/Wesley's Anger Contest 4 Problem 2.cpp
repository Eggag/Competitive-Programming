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

ll dp[5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi v(n + 1), p(n + 1);
	int sum = 0;
	repn(i, 1, n + 1) cin >> v[i] >> p[i], sum += p[i];
	rep(i, 5005) dp[i] = 1e18;
	dp[0] = 0;
	repn(i, 1, n + 1){
		for(int j = 5000 - p[i]; j >= 0; j--){
			dp[j + p[i]] = min(dp[j] + (v[i] + 2) / 2, dp[j + p[i]]);
		}
	}
	ll ans = 1e18;
	repn(i, (sum + 2) / 2, 5005) ans = min(ans, dp[i]);
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
