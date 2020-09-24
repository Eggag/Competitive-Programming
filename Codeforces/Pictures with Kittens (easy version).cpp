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

ll dp[205][205];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k, x;
	cin >> n >> k >> x;
	vector<ll> a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	rep(i, n + 1) rep(j, x + 1) dp[i][j] = -1e18;
	dp[0][x] = 0;
	repn(i, 1, n + 1){
		for(int j = x - 1; j >= 0; j--){
			repn(l, max(0, i - k), i){
				dp[i][j] = max(dp[i][j], dp[l][j + 1] + a[i]);
			}
		}
	}
	ll mx = -1e18;
	repn(i, n - k + 1, n + 1) mx = max(mx, dp[i][0]);
	if(mx <= -1e17) mx = -1;
	cout << mx << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
