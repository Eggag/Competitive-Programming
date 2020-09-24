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
const int mxN = 205;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, L;
ll dp[mxN][mxN][mxN][2];

int solve(vector<pi> x){
	rep(i, n + 1) rep(j, n + 1) rep(k, n + 1) rep(l, 2) dp[i][j][k][l] = 1e18;
	dp[0][0][0][0] = dp[0][0][0][1] = 0;
	rep(i, n + 1) rep(j, n + 1 - i) rep(k, min(n + 1, i + j + 1)) rep(l, 2) if(dp[i][j][k][l] < 1e18 && (i + j) <= n){
		if(l == 0){
			int nm = 0;
			repn(i1, i + 1, n + 1){
				if((j + i1) <= n){
					ll dist = dp[i][j][k][l] + (j ? x[j - 1].fi : 0) + (L - x[n - i1].fi);
					if(x[n - i1].se >= dist) nm++;
					dp[i1][j][k + nm][l ^ 1] = min(dp[i1][j][k + nm][l ^ 1], dist);
				}
				else break;
			}
		}
		else{
			int nm = 0;
			repn(j1, j + 1, n + 1){
				if((i + j1) <= n){
					ll dist = dp[i][j][k][l] + x[j1 - 1].fi + (i ? (L - x[n - i].fi) : 0);
					if(x[j1 - 1].se >= dist) nm++;
					dp[i][j1][k + nm][l ^ 1] = min(dp[i][j1][k + nm][l ^ 1], dist);
				}
				else break;
			}
		}
	}
	for(int k = n; k >= 0; k--){
		rep(i, n + 1) rep(j, n + 1) rep(l, 2){
			if(dp[i][j][k][l] != 1e18) return k;
		}	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> L;
	vector<pi> x(n);
	rep(i, n) cin >> x[i].fi;
	rep(i, n) cin >> x[i].se;
	int mx = solve(x);
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
