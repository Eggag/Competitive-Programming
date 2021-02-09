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

struct seg{
	int sz;
	int mn[1 << 19], mx[1 << 19];
	void update(int p, int val){
		for(mx[p + sz] = val, mn[p += sz] = val; p > 1; p >>= 1){
			mx[p >> 1] = max(mx[p], mx[p ^ 1]);
			mn[p >> 1] = min(mn[p], mn[p ^ 1]);
		}
	}
	int queryMax(int l, int r){
		r++;
		int res = -1e9;
		for(l += sz, r += sz; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = max(res, mx[l++]);
			if(r & 1) res = max(res, mx[--r]);
		}
		return res;
	}
	int queryMin(int l, int r){
		r++;
		int res = 1e9;
		for(l += sz, r += sz; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = min(res, mn[l++]);
			if(r & 1) res = min(res, mn[--r]);
		}
		return res;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<seg> tree(1 << k);
	rep(i, 1 << k) rep(j, 1 << 19){
		tree[i].sz = n;
		tree[i].mn[j] = 1e9, tree[i].mx[j] = -1e9;
	}
	rep(i, n){
		vi a(k);
		rep(j, k) cin >> a[j];
		rep(j, 1 << k){
			int cur = 0;
			rep(l, k){
				if(j & (1 << l)) cur += a[l];
				else cur += -1 * a[l];
			}
			tree[j].update(i, cur);
		}
	}
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
				tree[j].update(p, cur);
			}
		}
		else{
			int l, r;
			cin >> l >> r;
			l--, r--;
			int bst = 0;
			rep(j, 1 << k) bst = max(bst, tree[j].queryMax(l, r) - tree[j].queryMin(l, r));
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
