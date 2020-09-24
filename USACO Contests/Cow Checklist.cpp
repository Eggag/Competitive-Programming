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
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN][mxN][2];

ll dist(pi a, pi b){
	return (ll)((ll)(sq((ll)(a.fi - b.fi)) + sq((ll)(a.se - b.se))));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
	int h, g;
	cin >> h >> g;
	vector<pi> p(h), p1(g);
	rep(i, h) cin >> p[i].fi >> p[i].se;
	rep(i, g) cin >> p1[i].fi >> p1[i].se;
	rep(i, mxN) rep(j, mxN) rep(k, 2) dp[i][j][k] = 1e18;
	rep(i, h){
		rep(j, g + 1){
			if(!j){
				if(!i) dp[i][j][0] = 0LL;
				else dp[i][j][0] = dp[i - 1][j][0] + dist(p[i], p[i - 1]);
			}
			else{
				//if 1 we just dist with j - 1
				//if 0 we just dist with ourselves
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dist(p[i], p1[j - 1]));
				if(j > 1) dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dist(p1[j - 2], p1[j - 1]));
				//
				if(i) dp[i][j][0] = min({dp[i][j][0], dp[i - 1][j][1] + dist(p1[j - 1], p[i]), dp[i - 1][j][0] + dist(p[i], p[i - 1])});
			}
		}
	}
	cout << dp[h - 1][g][0] << endl; //all processed, last not taken
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
