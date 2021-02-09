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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int b[1 << 6][mxN];

struct seg{
	int n;
	int mn[1 << 6][1 << 19], mx[1 << 6][1 << 19];
	void build(int msk, int id, int l, int r){
		if(l == r){
			mn[msk][id] = mx[msk][id] = b[msk][l];
			return;
		}
		int m = (l + r) / 2;
		build(msk, id << 1, l, m);
		build(msk, id << 1 | 1, m + 1, r);
		mn[msk][id] = min(mn[msk][id << 1], mn[msk][id << 1 | 1]);
		mx[msk][id] = max(mx[msk][id << 1], mx[msk][id << 1 | 1]);
	}
	void build(int msk){
		build(msk, 1, 0, n);
	}
	void update(int id, int l, int r, int p, int val, int msk){
		if(l == r){
			mn[msk][id] = mx[msk][id] = val;
			return;
		}
		int m = (l + r) / 2;
		if(p <= m) update(id << 1, l, m, p, val, msk);
		else update(id << 1 | 1, m + 1, r, p, val, msk);
		mn[msk][id] = min(mn[msk][id << 1], mn[msk][id << 1 | 1]);
		mx[msk][id] = max(mx[msk][id << 1], mx[msk][id << 1 | 1]);
	}
	void update(int p, int val, int msk){
		update(1, 0, n, p, val, msk);
	}
	int queryMin(int id, int l, int r, int x, int y, int msk){
		if(x > r || y < l) return 1e9;
		if(l >= x && r <= y) return mn[msk][id];
		int m = (l + r) / 2;
		return min(queryMin(id << 1, l, m, x, y, msk), queryMin(id << 1 | 1, m + 1, r, x, y, msk));
	}
	int queryMin(int l, int r, int msk){
		return queryMin(1, 0, n, l, r, msk);
	}
	int queryMax(int id, int l, int r, int x, int y, int msk){
		if(x > r || y < l) return -1e9;
		if(l >= x && r <= y) return mx[msk][id];
		int m = (l + r) / 2;
		return max(queryMax(id << 1, l, m, x, y, msk), queryMax(id << 1 | 1, m + 1, r, x, y, msk));
	}
	int queryMax(int l, int r, int msk){
		return queryMax(1, 0, n, l, r, msk);
	}
} tree;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	tree.n = n;
	rep(i, 1 << 6) rep(j, 1 << 19) tree.mn[i][j] = 1e9, tree.mx[i][j] = -1e9;
	rep(i, n){
		vi a(k);
		rep(j, k) cin >> a[j];
		rep(j, 1 << k){
			int cur = 0;
			rep(l, k){
				if(j & (1 << l)) cur += a[l];
				else cur += -1 * a[l];
			}
			b[j][i] = cur;
		}
	}
	rep(i, 1 << k) tree.build(i);
	int q;
	cin >> q;
	rep(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int p;
			cin >> p;
			p--;
			vi up(k);
			rep(j, k) cin >> up[j];
			rep(j, 1 << k){
				int cur = 0;
				rep(l, k){
					if(j & (1 << l)) cur += up[l];
					else cur += -1 * up[l];
				}
				tree.update(p, cur, j);
			}
		}
		else{
			int l, r;
			cin >> l >> r;
			l--, r--;
			int bst = 0;
			rep(j, 1 << k) bst = max(bst, tree.queryMax(l, r, j) - tree.queryMin(l, r, j));
			cout << bst << endl;
		}
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
