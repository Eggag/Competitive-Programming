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
const int mxN = 105;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll g[mxN][mxN];

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	ll ans = 0LL;
	rep(i, (n + 1) / 2){
		rep(j, (m + 1) / 2){
			vector<ll> cur = {g[i][j]};
			if((n - 1 - i) != i) cur.pb(g[n - 1 - i][j]), cur.pb(g[n - i - 1][m - j - 1]);
			if((m - 1 - j) != j){
				cur.pb(g[i][m - 1 - j]);
				if((n - 1 - i) == i) cur.pb(g[n - i - 1][m - j - 1]);
			}
			ll bst = 1e18;
			rep(k, cur.size()){
				ll tot = 0;
				rep(l, cur.size()) tot += abs(cur[l] - cur[k]);
				bst = min(tot, bst);
			}
			ans += bst;
		}
	}
	cout << ans << endl;
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
