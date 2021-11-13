#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int ans[mxN][mxN];
int g[mxN][mxN];

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) ans[i][j] = -1;
	rep(i, n) rep(j, m) cin >> g[i][j];
	vector<array<int, 3>> p;
	rep(i, n) rep(j, m){
		p.pb({g[i][j], i, j});
	}
	sort(all(p));
	rep(i, m) ans[p[i][1]][i] = p[i][0];
	rep(i, n){
		vi cr;
		int st = 0;
		rep(j, m) cr.pb(g[i][j]);
		rep(j, m) if(ans[i][j] != -1) st++;
		sort(all(cr));
		rep(j, m) if(ans[i][j] == -1){
			ans[i][j] = cr[st++];
		}
	}
	rep(i, n){
		rep(j, m) cout << ans[i][j] << " ";
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
