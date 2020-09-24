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

pi dp[20005][2];

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	rep(i, 20005) dp[i][0] = {1e9, 0};
	rep(i, 20005) dp[i][1] = {1e9, 0};
	for(int i = -5000; i <= 5000; i++){
		int a1 = a + i;
		if(a1 > 0){
			dp[a1][0].fi = min(abs(i), dp[a1][0].fi);
			for(int j = a1 + a1; j <= 15000; j += a1) dp[j][0].fi = min(dp[j][0].fi, dp[a1][0].fi);
		}
	}
	for(int i = -5000; i <= 5000; i++){
		int b1 = b + i;
		if(b1 > 0 && dp[b1][0].fi != 1e9){
			if(dp[b1][1].fi > (dp[b1][0].fi + abs(i))){
				dp[b1][1].fi = dp[b1][0].fi + abs(i);
				dp[b1][1].se = b1;
			}
			for(int j = b1 + b1; j <= 15000; j += b1){
				if(dp[j][1].fi > dp[b1][1].fi){
					dp[j][1].fi = dp[b1][1].fi;
					dp[j][1].se = b1;
				}
			}
		}
	}
	int ans = 1e9;
	int b2 = 0, c2 = 0;
	for(int i = -5000; i <= 5000; i++){
		int c1 = c + i;
		if(c1 > 0){
			//ans = min(ans, abs(i) + dp[c1][1].fi);
			if(ans > (dp[c1][1].fi + abs(i))){
				ans = dp[c1][1].fi + abs(i);
				c2 = c1, b2 = dp[c1][1].se;
			}
		}
	}
	int bst = 1e9;
	int a2 = 0;
	for(int i = -5000; i <= 5000; i++){
		int a1 = a + i;
		if(a1 > 0){
			if(b2 % a1 == 0){
				if(abs(i) < bst){
					bst = abs(i);
					a2 = a1;
				}
			}
		}
	}
	//debug(bst);
	//debug2(b2, c2);
	//assert((abs(a - a2) + abs(b - b2) + abs(c - c2)) == ans);
	cout << ans << endl;
	cout << a2 << " " << b2 << " " << c2 << endl;
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
