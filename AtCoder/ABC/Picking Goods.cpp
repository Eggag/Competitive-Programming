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
const int mxN = 3005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pair<ll, array<int, 3>> dp[mxN][mxN][4];
int val[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	rep(i, k){
		int a, b, d;
		cin >> a >> b >> d;
		a--, b--;
		val[a][b] = d;
	}
	if(!val[0][0]){
		array<int, 3> ar = {0, 0, 0};
		dp[0][0][0].fi = 0LL;
		dp[0][0][0].se = ar;
	}
	else{
		array<int, 3> ar = {val[0][0], 0, 0};
		dp[0][0][1].fi = val[0][0];
		dp[0][0][1].se = ar;
	}
	rep(i, n) rep(j, m) rep(x, 4) repn(x1, x, min(4, x + 2)){
		if(!i && !j) continue;
		if(j){
			if(x == 3){
				ll sm = 0LL, sm1 = 0LL;
				vi a;
				rep(l, 3) a.pb(dp[i][j - 1][x].se[l]), sm += a[l];
				a.pb(val[i][j]);
				sort(all(a));
				reverse(all(a));
				rep(l, 3) sm1 += a[l];
				if((dp[i][j - 1][x].fi + (sm1 - sm)) > dp[i][j][x].fi){
					dp[i][j][x] = dp[i][j - 1][x];
					dp[i][j][x].fi += sm1 - sm;
					rep(l, 3) dp[i][j][x].se[l] = a[l];
				}
			}
			else{
				if(x1 > x){
					if(val[i][j]){
						if(dp[i][j][x1].fi < dp[i][j - 1][x].fi + val[i][j]){
							dp[i][j][x1] = dp[i][j - 1][x];
							dp[i][j][x1].fi += val[i][j];
							//now we put them all in order
							vi a;
							rep(l, 3) a.pb(dp[i][j - 1][x].se[l]);
							a.pb(val[i][j]);
							sort(all(a));
							reverse(all(a));
							rep(l, 3) dp[i][j][x1].se[l] = a[l];
						}
					}
				}
				else{
					if(!val[i][j]){
						if(dp[i][j][x1].fi < dp[i][j - 1][x].fi){
							dp[i][j][x1] = dp[i][j - 1][x];
						}
					}	
					else{
						ll sm = 0LL, sm1 = 0LL;
						vi a;
						rep(l, 3) a.pb(dp[i][j - 1][x].se[l]), sm += a[l];
						a.pb(val[i][j]);
						sort(all(a));
						reverse(all(a));
						rep(l, x) sm1 += a[l];
						if((dp[i][j - 1][x].fi + (sm1 - sm)) > dp[i][j][x].fi){
							dp[i][j][x] = dp[i][j - 1][x];
							dp[i][j][x].fi += sm1 - sm;
							rep(l, x) dp[i][j][x].se[l] = a[l];
							repn(l, x, 3) dp[i][j][x].se[l] = 0;
						}
					}
				}
			}
		}
		if(i){
			if(val[i][j]){
				if(dp[i][j][1].fi < dp[i - 1][j][x].fi + val[i][j]){
					dp[i][j][1] = dp[i - 1][j][x];
					rep(l, 3) dp[i][j][1].se[l] = 0;
					dp[i][j][1].se[0] = val[i][j];
					dp[i][j][1].fi += val[i][j];
				}
			}
			else{
				if(dp[i][j][0].fi < dp[i - 1][j][x].fi){
					dp[i][j][0] = dp[i - 1][j][x];
					rep(l, 3) dp[i][j][0].se[l] = 0;
				}
			}
		}
	}
	ll mx = 0LL;
	rep(i, 4) mx = max(mx, dp[n - 1][m - 1][i].fi);
	cout << mx << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
