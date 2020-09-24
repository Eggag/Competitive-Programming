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

int dp[100005][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi x(n);
	rep(i, n) cin >> x[i];
	rep(i, n){
		if(x[i]){
			if(!i) dp[i][x[i]] = 1;
			else{
				(dp[i][x[i]] += (dp[i - 1][x[i]] + dp[i - 1][x[i] + 1]) % MOD) %= MOD;
				if(x[i] > 0) (dp[i][x[i]] += dp[i - 1][x[i] - 1]) %= MOD;
			}
		}
		else{
			repn(j, 1, m + 1){
				x[i] = j;
				if(!i) dp[i][x[i]] = 1;
				else{
					(dp[i][x[i]] += (dp[i - 1][x[i]] + dp[i - 1][x[i] + 1]) % MOD) %= MOD;
					if(x[i] > 0) (dp[i][x[i]] += dp[i - 1][x[i] - 1]) %= MOD;
				}
			}
		}
	}
	ll ans = 0;
	repn(i, 1, m + 1) (ans += dp[n - 1][i]) %= MOD;
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
