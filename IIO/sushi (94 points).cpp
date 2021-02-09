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
const int mxN = 1e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pi dp[mxN];

bool check(int n, int b, vi a, int g){
	dp[0] = {1, 0};
	repn(i, 1, b + 1) dp[i] = {0, 0};
	rep(i, n){
		rep(j, b + 1) dp[j].se = 0;
		for(int j = a[i]; j <= b; j++) if(dp[j - a[i]].fi){
			if(dp[j].fi && dp[j - a[i]].se < g) dp[j].se = min(dp[j].se, dp[j - a[i]].se + 1);
			else if(dp[j - a[i]].se < g) dp[j] = dp[j - a[i]], dp[j].se++;
		}

	}
	return dp[b].fi;
}

int sushi(int n, int b, vi a){
	if(n == 1){
		if(b % a[0] == 0) return b / a[0];
		return -1;
	}
	int l = 1, r = b + 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(n, b, a, mid)) r = mid;
		else l = mid + 1;
	}
	if(r == (b + 1)) l = -1;
	return l;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
