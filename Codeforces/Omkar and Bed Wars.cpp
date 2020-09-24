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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][2][2];

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 1e9;
	rep(j1, 2) rep(k1, 2) rep(l1, 2){
		//1 is LEFT
		//0 is RIGHT
		if(j1 == k1 && k1 == l1 && j1 == l1) continue;
		rep(i, n) rep(j, 2) rep(k, 2) dp[i][j][k] = 1e9;
		if(s[0] == 'L'){
			if(j1 == 1) dp[0][j1][k1] = 0;
			else dp[0][j1][k1] = 1;
		}
		else{
			if(!j1) dp[0][j1][k1] = 0;
			else dp[0][j1][k1] = 1;
		}
		repn(i, 1, n){
			rep(j, 2) rep(k, 2) rep(l, 2){
				int cst = 0;
				if(s[i] == 'L' && !j) cst = 1;
				if(s[i] == 'R' && j) cst = 1;
				if(j == k && k == l && j == l) continue; // bad state
				dp[i][j][k] = min(dp[i - 1][k][l] + cst, dp[i][j][k]);
			}
		}
		ans = min(ans, dp[n - 1][k1][l1]);
	}
	cout << ans << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
