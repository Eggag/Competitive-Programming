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
const ll inf = 1e18;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN][205];
vector<pi> st[mxN], en[mxN];
pi bst[mxN]; //for the position i this is the move we make (gain first, move to second)

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<array<int, 4>> a(k);
	rep(i, k){
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
		st[a[i][0]].pb(mp(a[i][3], a[i][2])); //first cost, then latest
		en[a[i][1]].pb(mp(a[i][3], a[i][2]));
	}
	rep(i, mxN) rep(j, 205) dp[i][j] = inf;
	multiset<pair<int, int>> cr;
	repn(i, 1, n + 1){
		for(pi x : st[i]) cr.insert(x);
		if(cr.size()) bst[i] = *(--cr.end());
		else bst[i] = {0, i}; //we gain nothing and move to the next point in time
		for(pi x : en[i]) cr.erase(cr.find(x));
	}
	dp[1][0] = 0LL;
	repn(i, 1, n + 2) rep(j, m + 1) if(dp[i][j] != inf){
		dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
		dp[bst[i].se + 1][j] = min(dp[bst[i].se + 1][j], dp[i][j] + bst[i].fi);
	}
	ll ans = inf;
	rep(i, m + 1) ans = min(ans, dp[n + 1][i]);
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
