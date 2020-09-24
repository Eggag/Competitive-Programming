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
const int mxN = 1e5 + 5;
const int logn = 21;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN], mn[logn][mxN];

int minQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return min(mn[t][l], mn[t][r - (1 << t)]);
}

ll dp[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, c;
	cin >> n >> c;
	ll sum = 0LL;
	rep(i, n) cin >> a[i], sum += a[i];
	memcpy(mn[0], a, sizeof a);
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) <= n; i++){
			mn[l + 1][i] = min(mn[l][i], mn[l][i + (1 << l)]);
		}
	}
	ll mx = 0LL, ans = 0LL;
	rep(i, n){
		if(i >= c) mx = max(mx, dp[i - c]);
		dp[i] = (ll)(mx + 1LL * (i >= (c - 1) ? minQ(i - (c - 1), i + 1) : 0LL));
		ans = max(ans, dp[i]);
	}
	cout << sum - ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
