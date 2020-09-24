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

int dp[1005][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	//compute prefix sums to get all the costs in O(1)
	vi cnt(m, 0);
	rep(j, m){
		int cur = 0;
		rep(i, n) cur += (s[i][j] == '#');
		cnt[j] = cur;
		if(j) cnt[j] += cnt[j - 1];
	}
	//this is just a 2 state dp
	rep(i, 1005) rep(j, 2) dp[i][j] = 1e9;
	rep(i, m){
		repn(j, max(0, i - (y - 1)), i - (x - 1) + 1){
			dp[i][1] = min({dp[i][1], (j ? dp[j - 1][0] : 0) + (n * (i - j + 1)) - (cnt[i] - (j ? cnt[j - 1] : 0))});
		}
		repn(j, max(0, i - (y - 1)), i - (x - 1) + 1){
			dp[i][0] = min({dp[i][0], (j ? dp[j - 1][1] : 0) + (cnt[i] - (j ? cnt[j - 1] : 0))});
		}
	}
	cout << min(dp[m - 1][0], dp[m - 1][1]) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
