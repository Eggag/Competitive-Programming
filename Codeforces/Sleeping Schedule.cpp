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

int n, h, l, r;
int dp[2005][2005];
int pos[2005][2005];

bool good(int m){
	return (m >= l && m <= r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> h >> l >> r;
	vi a(n);
	rep(i, n) cin >> a[i];
	rep(i, 2005) rep(j, 2005) dp[i][j] = 0;
	rep(i, 2005) rep(j, 2005) pos[i][j] = 0;
	dp[0][a[0]] = good(a[0]);
	dp[0][a[0] - 1] = good(a[0] - 1);
	pos[0][a[0]] = 1;
	pos[0][a[0] - 1] = 1;
	repn(i, 1, n){
		rep(j, h){ //prev sleep time
			if(pos[i - 1][j]){
				dp[i][(j + a[i]) % h] = max(dp[i][(j + a[i]) % h], dp[i - 1][j] + good((j + a[i]) % h));
				pos[i][(j + a[i]) % h] = 1;
			}
			if(pos[i - 1][j]){
				dp[i][(j + a[i] - 1) % h] = max(dp[i][(j + a[i] - 1) % h], dp[i - 1][j] + good((j + a[i] - 1) % h));
				pos[i][(j + a[i] - 1) % h] = 1;
			}
		}
	}
	int ans = 0;
	rep(i, h) ans = max(ans, dp[n - 1][i]);
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
