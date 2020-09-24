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

int dp[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("taxiin.txt", "r", stdin);
	freopen("taxiout.txt", "w", stdout);
	int s, n;
	cin >> s >> n;
	vector<pi> a(n);
	rep(i, n) cin >> a[i].fi >> a[i].se;
	rep(i, 100005) dp[i] = 1e9;
	dp[0] = 0;
	rep(i, n){
		for(int j = 0; j <= (s - a[i].se); j++){
			dp[min(j + a[i].se, s)] = min(dp[min(s, j + a[i].se)], dp[j] + a[i].fi);
		}
		a[i].se--;
		for(int j = 0; j <= (s - a[i].se); j++){
			dp[min(j + a[i].se, s)] = min(dp[min(s, j + a[i].se)], dp[j] + a[i].fi);
		}
	}
	cout << dp[s] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
