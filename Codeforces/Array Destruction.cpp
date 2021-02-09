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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int cnt[mxN];

void solve(){
	int n;
	cin >> n;
	vector<pi> a(2 * n);
	rep(i, 2 * n) cin >> a[i].fi, a[i].se = i, g[a[i].fi].clear();
	sort(all(a));
	rep(i, 2 * n) g[a[i].fi].pb(a[i].se);
	rep(i, 2 * n - 1){
		vector<pi> ans;
		ans.pb(mp(a[i].fi, a[2 * n - 1].fi));
		rep(j, 2 * n) cnt[a[j].fi] = 0;
		cnt[a[i].fi]++, cnt[a[2 * n - 1].fi]++;
		int r = 2 * n - 2;
		if(cnt[a[r].fi] >= (int)g[a[r].fi].size()) r--;
		int x = a[2 * n - 1].fi;
		rep(j, n - 1){
			int y = x - a[r].fi;
			cnt[a[r].fi]++;
			if(cnt[y] >= (int)g[y].size()) break;
			int ind = g[y][cnt[y]++];
			ans.pb(mp(a[r].fi, y));
			x = a[r].fi;
			r--;
			while(r >= 0 && cnt[a[r].fi] >= (int)g[a[r].fi].size()) r--;
		}
		if((int)ans.size() == n){
			cout << "YES" << '\n';
			cout << a[i].fi + a[2 * n - 1].fi << '\n';
			rep(j, n) cout << ans[j].fi << " " << ans[j].se << '\n';
			goto end;
		}
	}
	cout << "NO" << '\n';
	end:;
	rep(j, 2 * n) g[a[j].fi].clear();
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
