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
const int mxN = 100005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[2][mxN];
vi h[mxN];
unordered_map<int, int> pos[2];

struct seg{
	int sz;
	int dat[1 << 18];
	seg(int s){
		sz = s;
		rep(i, 1 << 18) dat[i] = 0;
	}
	void update(int id, int l, int r, int pos, int x){
		if(l == r){
			dat[id] = max(dat[id], x);
			return;
		}
		int m = (l + r) / 2;
		if(pos <= m) update(id << 1, l, m, pos, x);
		else update(id << 1 | 1, m + 1, r, pos, x);
		dat[id] = max(dat[id << 1], dat[id << 1 | 1]);
	}
	void update(int pos, int x){
		update(1, 0, sz, pos, x);
	}
	int query(int id, int l, int r, int x, int y){
		if(x > r || y < l) return 0;
		if(l >= x && r <= y) return dat[id];
		int m = (l + r) / 2;
		return max(query(id << 1, l, m, x, y), query(id << 1 | 1, m + 1, r, x, y));
	}
	int query(int l, int r){
		return query(1, 0, sz, l, r);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, 2) rep(j, n) cin >> g[i][j], pos[i][g[i][j] - 1] = j + 1;
	rep(i, n){
		for(int j = i - 4; j <= i + 4; j++) if(pos[1][j]) h[i].pb(pos[1][j] - 1);
		sort(all(h[i]));
	}
	seg tree(n);
	rep(i, n){
		int nm = g[0][i] - 1;
		for(int j = h[nm].size() - 1; j >= 0; j--){
			tree.update(h[nm][j] + 1, tree.query(0, h[nm][j]) + 1);
		}
	}
	cout << tree.query(0, n) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
