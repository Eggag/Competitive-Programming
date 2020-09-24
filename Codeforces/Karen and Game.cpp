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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int g[n][m];
	int gc = 0;
	rep(i, n) rep(j, m) cin >> g[i][j], gc = gcd(gc, g[i][j]);
	if(gc) rep(i, n) rep(j, m) g[i][j] /= gc;
	int mn = 1e9;
	rep(j, m) mn = min(mn, g[0][j]); //lower bound for k
	vector<pair<string, int>> ret;
	int mna = 1e9;
	int f1 = 0;
	rep(k, mn + 1){
		int cur[n][m];
		memset(cur, 0, sizeof(cur));
		vector<pair<string, int>> ans;
		rep(i, k) ans.pb({"row ", 1});
		rep(j, m) cur[0][j] = k;
		rep(j, m){
			rep(i, g[0][j] - k) ans.pb({"col ", j + 1});
			rep(i, n) cur[i][j] += (g[0][j] - k);
		}
		repn(i, 1, n){
			int mx = 0;
			rep(j, m) mx = max(mx, g[i][j] - cur[i][j]);
			rep(j, m) cur[i][j] += mx;
			if(mx > 0) rep(l, mx) ans.pb({"row ", i + 1});
		}
		int f = 1;
		rep(i, n) rep(j, m){
			if(g[i][j] != cur[i][j]) f = 0;
		}
		if(f){
			if((int)ans.size() < mna) mna = (int)(ans.size()), ret = ans, f1 = 1;
		}
	}
	if(!f1) cout << -1 << endl;
	else{
		cout << mna * gc << endl;
		for(auto s : ret) rep(j, gc) cout << s.fi << s.se << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
