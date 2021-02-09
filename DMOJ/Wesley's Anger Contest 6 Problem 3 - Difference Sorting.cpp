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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dat[1 << 21];

struct seg{
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 21); i++){
			dat[i] = 0;
		}
	}
	void update(int i, int s, int e, int x, ll v){
		if(s == e){
			dat[i] = max(dat[i], v);
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
		if(e < x || y < s) return 0;
		if(x <= s && e <= y) return dat[i];
		int m = (s + e) / 2;
		return max(query(i << 1, s, m, x, y), query(i << 1 | 1, m + 1, e, x, y));
	}
	ll query(int x, int y){
		return query(1, 0, sz, x, y);
	}
};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<ll, int>> a(n);
	rep(i, n) cin >> a[i].fi, a[i].se = i;
	sort(all(a));
	seg tree(n);
	rep(i, n - 1) tree.update(i, a[i + 1].fi - a[i].fi);
	ll ans = 0;
	rep(i, n){
		int l = i, r = a[i].se;
		if(r < l) swap(l, r);
		r--;
		if(l <= r) ans = max(ans, tree.query(l, r));
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
