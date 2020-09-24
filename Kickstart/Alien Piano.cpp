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

int dp[10005][5];

int solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) rep(j, 4) dp[i][j] = 1e9;
	rep(i, n) cin >> a[i];
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[0][3] = 0;
	repn(i, 1, n){
		rep(j, 4) rep(k, 4){ //j is prev, k is cur
			if(a[i] == a[i - 1]){
				dp[i][k] = min(dp[i][k], dp[i - 1][j] + (j != k));
			}
			else if(a[i] > a[i - 1]){
				dp[i][k] = min(dp[i][k], dp[i - 1][j] + (j >= k));
			}
			else{
				dp[i][k] = min(dp[i][k], dp[i - 1][j] + (j <= k));
			}
		}
	}
	return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << endl;
	}	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
