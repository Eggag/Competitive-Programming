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
const int MAXN = 10005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);
	int n, W;
	cin >> n >> W;
	vi w(n), t(n);
	rep(i, n) cin >> w[i] >> t[i];
	rep(i, MAXN) dp[i] = -1e9;
	dp[0] = 0;
	rep(i, n){
		for(int j = MAXN - w[i]; j >= 0; j--){
			dp[j + w[i]] = max(dp[j + w[i]], dp[j] + t[i]);
		}
	}
	pi best = {1, 1};
	repn(i, W, MAXN) if(dp[i] > 0){
		if(best.fi == -1 || (ll)(best.fi * i * 1LL) < (ll)(dp[i] * best.se * 1LL)){
			best = mp(dp[i], i);
		}	
	}
	ll ret = floor((ld)((1000.0 * best.fi) / (1.0 * best.se)));
	cout << ret << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
