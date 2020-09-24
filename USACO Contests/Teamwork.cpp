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

int a[10005];
int dp[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	repn(i, 1, n + 1) cin >> a[i];
	rep(i, 10005) dp[i] = -1e9;
	dp[0] = 0;
	dp[1] = a[1];
	repn(i, 2, n + 1){
		int mx = a[i];
		repn(j, 1, k + 1){
			if((i - j) < 0) break;
			if(i == j) dp[i] = max(dp[i], mx * j);
			else dp[i] = max(dp[i], dp[i - j] + (mx * j));
			mx = max(mx, a[i - j]);
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
