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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct seg{
	int sz;
	int dat[1 << 18];
	seg(int s){
		sz = s;
		rep(i, 1 << 18) dat[i] = 0;
	}
	void update(int id, int l, int r, int pos, int x){
		if(l == r){
			dat[id] += x;
			return;
		}
		int m = (l + r) / 2;
		if(pos <= m) update(id << 1, l, m, pos, x);
		else update(id << 1 | 1, m + 1, r, pos, x);
		dat[id] = dat[id << 1] + dat[id << 1 | 1];
	}
	void update(int pos, int x){
		update(1, 0, sz, pos, x);
	}
	int query(int id, int l, int r, int x, int y){
		if(x > r || y < l) return 0;
		if(l >= x && r <= y) return dat[id];
		int m = (l + r) / 2;
		return query(id << 1, l, m, x, y) + query(id << 1 | 1, m + 1, r, x, y);
	}
	int query(int l, int r){
		return query(1, 0, sz, l, r);
	}
};

int st[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	int n;
	cin >> n;
	vi a(2 * n);
	seg tree((2 * n) + 1);
	rep(i, 2 * n) cin >> a[i], a[i]--;
	vi vis(n, 0);
	ll tot = 0LL;
	rep(i, 2 * n){
		if(!vis[a[i]]){
			tree.update(i, 1);
			st[a[i]] = i;
			vis[a[i]] = 1;
		}
		else{
			tree.update(st[a[i]], -1);
			tot += tree.query(st[a[i]], i);
		}
	}
	cout << tot << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
