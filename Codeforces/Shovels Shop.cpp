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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[mxN], p[mxN];
int dp[mxN];

int sum(int l, int r){
	if(l > r) return 0;
	return p[r] - (l ? p[l - 1] : 0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	repn(i, 1, n + 1) cin >> a[i];
	vi mx(n + 1, 0);
	rep(i, m){
		int a, b;
		cin >> a >> b;
		mx[a] = max(mx[a], b);
	}
	sort(a, a + n + 1);
	p[0] = a[0];
	repn(i, 1, n + 1) p[i] = p[i - 1] + a[i];
	rep(i, mxN) dp[i] = 1e9;
	dp[0] = 0;
	rep(i, k + 1){
		repn(j, i + 1, k + 1){
			dp[j] = min(dp[j], dp[i] + sum(i + 1, j) - sum(i + 1, i + mx[j - i]));
		}
	}
	cout << dp[k] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
