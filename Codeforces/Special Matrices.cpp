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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, MOD;
ll dp[2][mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> MOD;
	vector<string> s(m);
	vi cnt(n, 0);
	int t = n, o = 0;
	rep(i, m){
		cin >> s[i];
		rep(j, n) if(s[i][j] == '1'){
			if(!cnt[j]) t--, o++;
			else o--;
			cnt[j]++;
		}
	}
	dp[(m - 1) & 1][t][o] = 1;
	repn(j, m, n){
		int cr = j & 1;
		rep(k, n + 1) rep(l, n + 1 - k) if(dp[cr ^ 1][k][l]){
			if(k > 1){
				ll uwu = 1LL * k * (k - 1) / 2;
				(dp[cr][k - 2][l + 2] += (dp[cr ^ 1][k][l] * uwu) % MOD) %= MOD;
			}
			if(l > 1){
				ll uwu = 1LL * l * (l - 1) / 2;
				(dp[cr][k][l - 2] += (dp[cr ^ 1][k][l] * uwu) % MOD) %= MOD;
			}
			if(k && l){
				ll uwu = 1LL * l * k;
				(dp[cr][k - 1][l] += (dp[cr ^ 1][k][l] * uwu) % MOD) %= MOD;
			}
		}
		memset(dp[cr ^ 1], 0, sizeof(dp[cr ^ 1]));
	}
	cout << dp[(n - 1) & 1][0][0] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
