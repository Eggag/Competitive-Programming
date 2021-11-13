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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	int mn = 1e9;
	rep(i, n) cin >> a[i], mn = min(mn, a[i]);
	map<int, int> dp;
	int ans = 1;
	rep(i, n){
		for(int j = 1; (j * j) <= a[i]; j++) if(a[i] % j == 0){
			if(j < mn){
				dp[j] = gcd(dp[j], a[i]);
			}
			if(a[i] / j != j && a[i] / j < mn){
				dp[a[i] / j] = gcd(dp[a[i] / j], a[i]);
			}
		}
	}
	for(pi x : dp) if(x.fi == x.se) ans++;
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
