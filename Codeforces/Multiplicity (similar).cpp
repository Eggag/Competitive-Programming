#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'
const int MOD = 1e9 + 7;
 
int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
ll dp[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	repn(i, 1, n){
		vi div;
		repn(j, 1, min(((int)(sqrt(a[i])) + 1), i + 2)){
			if(a[i] % j == 0){
				div.pb(j);
				if((a[i] / j) != j) div.pb(a[i] / j);
			} 
		}
		sort(all(div));
		reverse(all(div));
		rep(j, div.size()){
			dp[div[j]] = (dp[div[j] - 1] + dp[div[j]] + MOD) % MOD;
		}
	}
	ll ans = 0;
	repn(i, 1, n + 1) ans = (ans + dp[i]) % MOD;
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
