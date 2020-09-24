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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[20][20];
int dp[20][20];
int pref[20][20], cost[20][20];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, r, s;
	cin >> n >> m >> r >> s;
	rep(i, n) rep(j, m) cin >> g[i][j];
	int ans = 1e9;
	rep(i, (1 << (n - 1))) if(__builtin_popcount(i) == r){
		rep(k, 20) rep(j, 20) dp[k][j] = 1e9, pref[k][j] = 0, cost[k][j] = 0;
		rep(j, m){
			int ind = 0;
			rep(k, n){
				pref[ind][j] += g[k][j];
				if(i & (1 << k)) ind++;
			}
		}
		rep(k, 20) repn(j, 1, 20) pref[k][j] += pref[k][j - 1];
		rep(j, 20) repn(k, j + 1, 20){
			int nm = 0;
			rep(l, 20) nm = max(nm, pref[l][k] - pref[l][j]);
			cost[j][k] = nm;
		}
		rep(j, m){
			repn(k, 1, s + 2){
				if(k == 1){
					int nm = 0;
					rep(l, 20) nm = max(nm, pref[l][j]);
					dp[j][k] = nm;
				}
				else{
					rep(j1, j){
						dp[j][k] = min(dp[j][k], max(dp[j1][k - 1], cost[j1][j]));
					}
				}
			}
		}
		ans = min(ans, dp[m - 1][s + 1]);
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
