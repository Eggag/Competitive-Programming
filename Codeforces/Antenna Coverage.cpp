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

struct seg{
	int n, mn[1 << 20];
	seg(int s){
		n = s;
		rep(i, 1 << 20) mn[i] = 1e9;
	}
	void update(int id, int l, int r, int p, int x){
		if(l == r){
			mn[id] = min(mn[id], x);
			return;
		}
		int m = (l + r) / 2;
		if(p <= m) update(id << 1, l, m, p, x);
		else update(id << 1 | 1, m + 1, r, p, x);
		mn[id] = min(mn[id << 1], mn[id << 1 | 1]);
	}
	void update(int p, int x){
		update(1, 0, n, p, x);
	}
	int query(int id, int x, int y, int l, int r){
		if(x > r || y < l) return 1e9;
		if(x >= l && y <= r) return mn[id];
		int m = (x + y) / 2;
		return min(query(id << 1, x, m, l, r), query(id << 1 | 1, m + 1, y, l, r));
	}
	int query(int l, int r){
		return query(1, 0, n, l, r);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	sort(all(p));
	seg tree(m);
	rep(i, n){
		rep(j, m){
			int l = max(1, p[i].fi - p[i].se - j);
			int r = min(m, p[i].fi + p[i].se + j);
			int mn = (l == 1 ? 0 : tree.query(l - 1, r));
			tree.update(r, mn + j);
		}
	}
	cout << tree.query(m, m) << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
