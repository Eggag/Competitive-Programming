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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct seg{
	ll dat[1 << 20];
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 20); i++){
			dat[i] = -1;
		}
	}
	void update(int i, int s, int e, int x, ll v){
		if(s == e){
			dat[i] = v;
			return;
		}
		int m = (s + e) / 2;
		if(x <= m) update(i << 1, s, m, x, v);
		else update(i << 1 | 1, m + 1, e, x, v);
		dat[i] = max(dat[i << 1], dat[i << 1 | 1]);
	}
	void update(int x, ll v){
		update(1, 0, sz, x, v);
	}
	ll query(int i, int s, int e, int x, int y){
		if(e < x || y < s) return -1;
		if(x <= s && e <= y) return dat[i];
		int m = (s + e) / 2;
		return max(query(i << 1, s, m, x, y), query(i << 1 | 1, m + 1, e, x, y));
	}
	ll query(int x, int y){
		return query(1, 0, sz, x, y);
	}
} tree(mxN);

bool cmp(pi a, pi b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se < b.se;
}

bool cmp1(pi a, pi b){
	if(a.fi != b.fi) return a.fi > b.fi;
	return a.se < b.se;
}

void solve(){
	int n;
	cin >> n;
	vector<pi> a(n);
	rep(i, n) cin >> a[i].fi, a[i].se = i;
	tree.sz = n + 1;
	rep(i, n + 1) tree.update(i, -1);
	sort(all(a), cmp);
	set<int> pos;
	ll ans = 0LL;
	vi mx(n + 1, -1);
	rep(i, n){
		int cur = tree.query(0, a[i].se);
		mx[a[i].se] = max(mx[a[i].se], cur);
		auto it = pos.lb(a[i].se);
		if(it != pos.begin()){
			it--;
			tree.update(a[i].se, *it);
		}
		pos.insert(a[i].se);
	}
	sort(all(a), cmp1);
	rep(i, n + 1) tree.update(i, -1);
	pos.clear();
	rep(i, n){
		int cur = tree.query(0, a[i].se);
		mx[a[i].se] = max(mx[a[i].se], cur);
		auto it = pos.lb(a[i].se);
		if(it != pos.begin()){
			it--;
			tree.update(a[i].se, *it);
		}
		pos.insert(a[i].se);
	}
	int mxx = -1;
	rep(i, n){
		mxx = max(mxx, mx[i]);
		ans += i - mxx;
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
