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
#define endl '\n'
const ll INF = 1e18;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	ll n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	ll dp[n + 1][2]; //cost
	rep(i, n + 1) rep(j, 2) dp[i][j] = 0;
	dp[0][0] = b;
	dp[0][1] = INF;
	repn(i, 1, n + 1){
		dp[i][0] = INF, dp[i][1] = INF;
		if(s[i - 1] == '1' || (i < n && s[i] == '1')){
			dp[i][0] = INF;
			dp[i][1] = min((dp[i - 1][1] + a + (b * 2)), dp[i - 1][0] + a * 2 + b * 2);
		}
		else{
			dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + a * 2 + b);
			dp[i][1] = min(dp[i - 1][1] + a + b * 2, dp[i - 1][0] + b * 2 + a * 2);
		}
	}
	cout << dp[n][0] << endl;
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
