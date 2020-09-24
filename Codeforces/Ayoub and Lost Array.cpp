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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[3][200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, l, r;
	cin >> n >> l >> r;
	if(l == r){
		if(l % 3 == 0){
			cout << 1 << endl;
		}
		else{
			cout << ((n % 3) == 0) << endl;
		}
		return 0;
	}
	ll num0 = (r / 3) - ((l - 1) / 3);
	ll num1 = ((r + 1) / 3) - ((l) / 3);
	ll num2 = (r - l + 1) - num0 - num1;
	memset(dp, 0, sizeof(dp));
	repn(i, 1, n + 1){
		if(i == 1){
			dp[0][1] = num0;
			dp[1][1] = num1;
			dp[2][1] = num2;
			continue;
		}
		dp[0][i] = (((dp[0][i - 1] * num0) % MOD) + ((dp[1][i - 1] * num2) % MOD) + ((dp[2][i - 1] * num1) % MOD)) % MOD;
		dp[1][i] = (((dp[0][i - 1] * num1) % MOD) + ((dp[1][i - 1] * num0) % MOD) + ((dp[2][i - 1] * num2) % MOD)) % MOD;
		dp[2][i] = (((dp[0][i - 1] * num2) % MOD) + ((dp[1][i - 1] * num1) % MOD) + ((dp[2][i - 1] * num0) % MOD)) % MOD;
	}
	cout << dp[0][n] % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
