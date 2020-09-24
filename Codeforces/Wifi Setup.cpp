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
const int MAXN = 2005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ld a, b;
ld dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("wifi.in", "r", stdin);
	freopen("wifi.out", "w", stdout);
	cin >> n >> a >> b;
	vector<ld> c(n);
	rep(i, n) cin >> c[i];
	sort(all(c));
	dp[0] = 0;
	repn(i, 1, n + 1){
		dp[i] = 1e18;
		repn(j, 1, i + 1){
			dp[i] = min(dp[i], (dp[j - 1] + (a + b * (ld)((c[i - 1] - c[j - 1]) / 2.0))));
		}
	}
	ll num = floor(dp[n]);
	if(abs(num - dp[n]) < 1e-9) cout << (ll)dp[n] << endl;
	else cout << fixed << setprecision(1) << dp[n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
