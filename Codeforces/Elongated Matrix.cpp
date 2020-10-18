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

int g[17][mxN];
int ch[17][17], ch1[17][17];
pi dp[2][(1 << 17)][17];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	if(n == 1){
		int res = 1e9;
		rep(j, m - 1) res = min(res, abs(g[0][j] - g[0][j + 1]));
		cout << res << endl;
		return 0;
	}
	int ans = 0;
	rep(i, n) repn(j, i + 1, n){
		int mn = 1e9;
		rep(k, m) mn = min(mn, abs(g[i][k] - g[j][k]));
		ch[i][j] = ch[j][i] = mn;
	}	
	rep(i, n) rep(j, n) if(i != j){
		int mn = 1e9;
		rep(k, m - 1) mn = min(mn, abs(g[i][k] - g[j][k + 1]));
		ch1[i][j] = mn;
	}	
	rep(i, n){
		rep(j, 2) rep(k, (1 << n)) rep(l, n) dp[j][k][l] = {0, 0};
		dp[0][(1 << i)][i] = {1e9, 1};
		repn(j, 1, n){
			int cur = (j & 1), pr = 1 - cur;
			if(j == (n - 1)){
				rep(k, (1 << n)) rep(l, n) if(dp[pr][k][l].se){
					rep(h, n) if(!(k & (1 << h))){
						int msk = k | (1 << h);
						if(dp[cur][msk][h].se){
							dp[cur][msk][h].fi = max(dp[cur][msk][h].fi, min({dp[pr][k][l].fi, ch[l][h], ch1[h][i]}));
						}
						else dp[cur][msk][h] = {min({ch1[h][i], dp[pr][k][l].fi, ch[l][h]}), 1};
					}
				}
			}
			else{
				rep(k, (1 << n)) rep(l, n) if(dp[pr][k][l].se){
					rep(h, n) if(!(k & (1 << h))){
						int msk = k | (1 << h);
						if(dp[cur][msk][h].se){
							dp[cur][msk][h].fi = max(dp[cur][msk][h].fi, min(dp[pr][k][l].fi, ch[l][h]));
						}
						else dp[cur][msk][h] = {min(dp[pr][k][l].fi, ch[l][h]), 1};
					}
				}
			}
			rep(k, (1 << n)) rep(l, n) dp[pr][k][l] = {0, 0};
		}
		rep(j, n) if(dp[(n - 1) & 1][(1 << n) - 1][j].se) ans = max(ans, dp[(n - 1) & 1][(1 << n) - 1][j].fi);
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
