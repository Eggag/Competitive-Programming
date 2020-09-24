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

int dp[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	dp[0] = 0;
	repn(i, 1, n + 1){
		int mx = a[i];
		for(int j = i - 1; j >= max(0, i - k); j--){
			dp[i] = max(dp[i], dp[j] + mx * (i - j));
			mx = max(mx, a[j]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
