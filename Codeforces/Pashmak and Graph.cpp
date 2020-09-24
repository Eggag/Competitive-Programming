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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> p[mxN];
int mx[3 * mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		p[w].pb({u, v});
	}
	vi dp0(n, 0);
	repn(i, 1, 1e5 + 5) if(p[i].size()){
		rep(j, p[i].size()){
			int a = p[i][j].fi, b = p[i][j].se;
			swap(a, b);
			dp0[a] = max(dp0[a], mx[b] + 1);
		}
		rep(j, p[i].size()) mx[p[i][j].se] = max(mx[p[i][j].se], dp0[p[i][j].se]);
	}
	int ans = 0;
	rep(i, n) ans = max(ans, dp0[i]);
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
