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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> p(n), b(m + 1);
	rep(i, n) cin >> p[i];
	rep(i, m + 1) cin >> b[i];
	rep(i, n) rep(j, k) dp[i][j] = 0LL;
	rep(i, n){
		rep(j, k + 1) rep(l, k + 1) if((j + l) <= k && (p[i] + l) <= m){
			if(!i){
				if(!j) dp[i][l] = max(dp[i][l], b[p[i] + l]);
			}
			else dp[i][j + l] = max(dp[i][j + l], dp[i - 1][j] + b[p[i] + l]);
		}
	}
	cout << dp[n - 1][k] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
