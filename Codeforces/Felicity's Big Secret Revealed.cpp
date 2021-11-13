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
#define inf 0x3f3f3f3f
const int MOD = 1e9 + 7;
const int mxN = 75;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][1 << 20];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi nxt(n, 1e9);
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == '1') nxt[i] = i;
		if(i < (n - 1)) nxt[i] = min(nxt[i], nxt[i + 1]);
	}
	//shitmask dp overrated
	memset(dp, 0, sizeof(dp));
	rep(i, n){
		dp[i][0] = 1;
		rep(msk, 1 << 20){
			if(!i && !msk){
				int j = nxt[i], num = 0;
				repn(k, j, min(j + 5, n)){
					num *= 2;
					if(s[k] == '1') num++;
					if(num < 20) dp[k][(1 << (num - 1))] = 1;
				}
			}
			if(!i || !dp[i - 1][msk]) continue;
			int cst = dp[i - 1][msk];
			int j = nxt[i], num = 0;
			repn(k, j, min(j + 5, n)){
				num *= 2;
				if(s[k] == '1') num++;
				if(num < 20){
					dp[k][msk | (1 << (num - 1))] += cst;
					if(dp[k][msk | (1 << (num - 1))] >= MOD) dp[k][msk | (1 << (num - 1))] -= MOD;
				}
			}
		}
	}
	int ans = 0LL;
	rep(i, n) repn(j, 1, 20) if(dp[i][(1 << j) - 1]){
		ans += dp[i][(1 << j) - 1];
		if(ans >= MOD) ans -= MOD;
	}
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
