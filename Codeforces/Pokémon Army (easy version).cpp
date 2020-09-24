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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN][2];

void solve(){
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) rep(j, 2) dp[i][j] = -1e18;
	ll mx0 = -1e18, mx1 = 0LL;
	rep(i, n){
		dp[i][0] = mx1 + a[i];
		if(mx0 >= 0) dp[i][1] = mx0 - a[i];
		mx1 = max(mx1, dp[i][1]);
		mx0 = max(mx0, dp[i][0]);
	}
	cout << max(mx0, mx1) << endl;
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
