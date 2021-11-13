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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
ll k;
ll a[25][25];
unordered_map<ll, ll> dp[25][25];
unordered_map<ll, ll> dp1[25][25];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, n) rep(j, m) cin >> a[i][j];
	dp[0][0][a[0][0]] = 1;
	rep(i, n) rep(j, m) if(i + j <= (n + m - 2) / 2){
		for(pair<ll, ll> x : dp[i][j]){
			if(i < (n - 1)) dp[i + 1][j][x.fi ^ a[i + 1][j]] += x.se;
			if(j < (m - 1)) dp[i][j + 1][x.fi ^ a[i][j + 1]] += x.se;
		}
	}
	int rm = (n + m - 2) - ((n + m - 2) / 2);
	dp1[n - 1][m - 1][a[n - 1][m - 1]] = 1;
	for(int i = n - 1; i >= 0; i--){
		for(int j = m - 1; j >= 0; j--) if((n - i - 1) + (m - j - 1) <= rm){
			for(pair<ll, ll> x : dp1[i][j]){
				if(i > 0) dp1[i - 1][j][x.fi ^ a[i - 1][j]] += x.se;
				if(j > 0) dp1[i][j - 1][x.fi ^ a[i][j - 1]] += x.se;
			}
		}
	}
	ll ans = 0LL;
	rep(i, n) rep(j, m) if((i + j) == (n + m - 2) / 2){
		unordered_map<ll, ll> sm;
		for(pair<ll, ll> y : dp1[i][j]) sm[y.fi] += y.se;
		for(pair<ll, ll> x : dp[i][j]){
			ans += x.se * sm[k ^ (x.fi ^ a[i][j])];
		}
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
