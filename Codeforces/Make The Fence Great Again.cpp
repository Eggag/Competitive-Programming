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

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	ll dp[n][3];
	rep(i, n) rep(j, 3) dp[i][j] = 1e18;
	dp[0][0] = 0;
	dp[0][1] = b[0];
	dp[0][2] = b[0] * 2;
	repn(i, 1, n){
		rep(j, 3) rep(k, 3){
			if((a[i] + j) != (a[i - 1] + k)){
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j * b[i]));
			}
		}
	}
	cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
