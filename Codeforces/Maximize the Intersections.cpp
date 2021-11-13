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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n, k;
	cin >> n >> k;
	vi vis(2 * n, 0);
	vector<pi> ed;
	rep(i, k){
		int x, y;
		cin >> x >> y;
		x--, y--;
		vis[x] = vis[y] = 1;
		ed.pb(mp(x, y));
	}
	vi a;
	rep(i, 2 * n) if(!vis[i]) a.pb(i);
	int m = (2 * n) - (2 * k);
	rep(i, m / 2) ed.pb(mp(a[i], a[i + (m / 2)]));
	int ans = 0;
	rep(i, ed.size()) repn(j, i + 1, ed.size()){
		int f = 0;
		int l = min(ed[j].fi, ed[j].se), r = max(ed[j].fi, ed[j].se);
		if(ed[i].fi < r && ed[i].fi > l) f++;
		if(ed[i].se < r && ed[i].se > l) f++;
		if(f == 1) ans++;
	}
	cout << ans << '\n';
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
