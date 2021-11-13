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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, n) cin >> a[i], b[i] = a[i];
	sort(all(b));
	int nm = 1;
	vi cnt(n + 2, 0), cnt1(n + 2, 0);
	vector<pi> p;
	repn(i, 1, n){
		if(b[i] == b[i - 1]) nm++;
		else{
			cnt1[1]++;
			cnt1[nm + 1]--;
			cnt[nm + 1] += nm;
			cnt[n + 1] -= nm;
			p.pb(mp(nm, b[i - 1]));
			nm = 1;
		}
	}
	cnt1[1]++;
	cnt1[nm + 1]--;
	cnt[nm + 1] += nm;
	cnt[n + 1] -= nm;
	p.pb(mp(nm, b[n - 1]));
	partial_sum(all(cnt), cnt.begin());
	partial_sum(all(cnt1), cnt1.begin());
	repn(i, 1, n + 2) cnt[i] += cnt1[i] * i;
	pi bst = {1, 1};
	repn(i, 1, n + 1){
		int x = cnt[i] / i;
		if(cnt[x] / x < i) continue;
		if(x * i >= bst.fi * bst.se) bst = {x, i};
	}
	int y = bst.fi, z = bst.se;
	vector<vi> g(y);
	rep(i, y) g[i].resize(z);
	rep(i, y) rep(j, z) g[i][j] = 0;
	sort(all(p));
	reverse(all(p));
	int x3 = 0, y3 = 0;
	int cnt2 = 0;
	rep(i, p.size()){
		int l = p[i].fi, nm = p[i].se;
		rep(j, (min(l, min(y, z)))){
			if(g[x3][y3] != 0) x3 = (x3 + 1) % y;
			if(!g[x3][y3]) g[x3][y3] = nm, cnt2++;
			x3 = (x3 + 1) % y;
			y3 = (y3 + 1) % z;
		}
	}
	cout << y * z << '\n';
	cout << y << " " << z << '\n';
	rep(i, y){
		rep(j, z) cout << g[i][j] << " ";
		cout << '\n';
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
