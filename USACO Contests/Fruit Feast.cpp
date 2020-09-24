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

int dp[5000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	int t, a, b;
	cin >> t >> a >> b;
	memset(dp, 0, sizeof(dp));
	//would've been morefun with huge constraints
	//that would force me to think harder :)
	dp[0] = 1;
	repn(i, 1, t + 1){
		if(i >= a) dp[i] |= dp[i - a];
		if(i >= b) dp[i] |= dp[i - b];
	}
	int ans = 0;
	for(int i = t; i >= 0; i--) if(dp[i]){
		ans = i;
		break;
	}
	repn(k, 1, t + 1) if(dp[k]){
		//what is the largest we could achieve?
		int j = k / 2;
		int ans1 = 0;
		for(int i = t - j; i >= 0 && (t - j - i) < (t - ans); i--) if(dp[i]){
			ans1 = i + j;
			break;
		}
		ans = max(ans, ans1);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
