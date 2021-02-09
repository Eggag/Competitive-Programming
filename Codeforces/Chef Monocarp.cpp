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
#define inf 0x3f3f3f3f
const int mxN = 205;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN * 3][mxN];

void solve(){
	int n;
	cin >> n;
	vi a(n), sp;
	vi vis(3 * n + 1, 0), cnt(n + 1, 0), b;
	rep(i, n) cin >> a[i], vis[a[i]] = 1;
	sort(all(a));
	repn(i, 1, 3 * n + 1) if(!vis[i]) sp.pb(i);
	rep(i, n){
		if(cnt[a[i]]) b.pb(a[i]);
		cnt[a[i]]++;
	}
	int m = sp.size();
	memset(dp, inf, sizeof(dp));
	dp[0][0] = 0;
	repn(i, 1, m + 1){
		rep(j, b.size() + 1){
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if(j < b.size()) dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + abs(sp[i - 1] - b[j]));
		}
	}
	cout << dp[m][b.size()] << '\n';
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
