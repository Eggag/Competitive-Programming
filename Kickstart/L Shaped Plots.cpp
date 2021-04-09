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

int g[mxN][mxN];
int l[mxN][mxN];
int r[mxN][mxN];
int d[mxN][mxN];
int u[mxN][mxN];

ll solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m){
		cin >> g[i][j];
		l[i][j] = r[i][j] = u[i][j] = d[i][j] = 0;
	}
	rep(i, n){
		l[i][0] = g[i][0];
		repn(j, 1, m){
			if(g[i][j]) l[i][j] = l[i][j - 1] + 1;
			else l[i][j] = 0;
		}
		r[i][m - 1] = g[i][m - 1];
		for(int j = m - 2; j >= 0; j--){
			if(g[i][j]) r[i][j] = r[i][j + 1] + 1;
			else r[i][j] = 0;
		}
	}
	rep(j, m){
		u[0][j] = g[0][j];
		repn(i, 1, n){
			if(g[i][j]) u[i][j] = u[i - 1][j] + 1;
			else u[i][j] = 0;
		}
		d[n - 1][j] = g[n - 1][j];
		for(int i = n - 2; i >= 0; i--){
			if(g[i][j]) d[i][j] = d[i + 1][j] + 1;
			else d[i][j] = 0;
		}
	}
	ll ans = 0;
	rep(i, n) rep(j, m){
		//u, r
		int a = u[i][j], b = r[i][j];
		ans += max(0, min(a - 1, (b / 2) - 1));
		ans += max(0, min(b - 1, (a / 2) - 1));
		//u, l
		a = u[i][j], b = l[i][j];
		ans += max(0, min(a - 1, (b / 2) - 1));
		ans += max(0, min(b - 1, (a / 2) - 1));
		//d, r
		a = d[i][j], b = r[i][j];
		ans += max(0, min(a - 1, (b / 2) - 1));
		ans += max(0, min(b - 1, (a / 2) - 1));
		//d, l
		a = d[i][j], b = l[i][j];
		ans += max(0, min(a - 1, (b / 2) - 1));
		ans += max(0, min(b - 1, (a / 2) - 1));
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
