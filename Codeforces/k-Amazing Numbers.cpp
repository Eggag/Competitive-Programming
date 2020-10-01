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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int res[mxN];

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n + 1) g[i].clear();
	rep(i, n) cin >> a[i], g[a[i]].pb(i);
	rep(i, n + 1) if(g[i].size()){
		int sm = g[i][0] + 1;
		repn(j, 1, g[i].size()) sm = max(sm, g[i][j] - g[i][j - 1]);
		sm = max(sm, n - g[i][(int)g[i].size() - 1]);
		res[i] = sm;
	}
	vi ans(n + 1, -1);
	int cr = n;
	rep(i, n + 1) if(g[i].size()){
		if(cr <= 0) break;
		while(res[i] <= cr) ans[cr] = i, cr--;
	}
	repn(i, 1, n + 1) cout << ans[i] << " ";
	cout << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
