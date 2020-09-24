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

int dp[100005][20];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	rep(i, 100005) rep(j, 20) dp[i][j] = 0;
	dp[0][0] = 1;
	repn(i, 1, n + 1){
		if(s[i - 1] == '?'){
			rep(k, 10) rep(j, 13){
				int cur = ((10 * j) + k) % 13;
				(dp[i][cur] += dp[i - 1][j]) %= MOD;
			}
		}
		else{
			rep(j, 13){
				int cur = ((10 * j) + (s[i - 1] - '0')) % 13;
				(dp[i][cur] += dp[i - 1][j]) %= MOD;
			}
		}
	}
	cout << dp[n][5] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
