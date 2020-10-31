#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int mxN = 1005;
const int MOD = 2012;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("bbreeds.in", "r", stdin);
	freopen("bbreeds.out", "w", stdout);
	string s;
	cin >> s;
	int n = (int)s.size();
	dp[0][0] = 1;
	int op = 0, cl = 0;
	repn(i, 1, n + 1){
		rep(h, i){
			//we need to reconstruct another state
			int g = op - h - cl;
			if(s[i - 1] == '('){
				(dp[i][h + 1] += dp[i - 1][h]) %= MOD;
				(dp[i][h] += dp[i - 1][h]) %= MOD;
			}
			else{
				if(h) (dp[i][h - 1] += dp[i - 1][h]) %= MOD;
				if(g) (dp[i][h] += dp[i - 1][h]) %= MOD;
			}
		}
		if(s[i - 1] == '(') op++;
		else cl++;
	}
	cout << dp[n][0] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
