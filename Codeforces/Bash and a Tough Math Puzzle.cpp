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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN];

struct seg{
	int dat[1 << 21];
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 21); i++){
			dat[i] = 0;
		}
	}
	void update(int i, int s, int e, int x, int v){
		if(s == e){
			dat[i] = v;
			return;
		}
		int m = (s + e) / 2;
		if(x <= m) update(i << 1, s, m, x, v);
		else update(i << 1 | 1, m + 1, e, x, v);
		dat[i] = gcd(dat[i << 1], dat[i << 1 | 1]);
	}
	void update(int x, int v){
		update(1, 0, sz, x, v);
	}
	int query(int i, int s, int e, int x, int y, int val){
		if(e < x || y < s) return -1;
		if(x <= s && e <= y){
			if(dat[i] % val == 0) return -1;
			while(s != e){
				int mid = (s + (e - s) / 2);
				if(dat[2 * i] % val != 0){
					i = 2 * i;
					e = mid;
				}
				else{
					i = 2 * i + 1;
					s = mid + 1;
				}
			}
			return s;
		}
		int m = (s + e) / 2;
		int uwu = query(i << 1, s, m, x, y, val);
		if(uwu != -1) return uwu;
		return query(i << 1 | 1, m + 1, e, x, y, val);
	}
	int query(int x, int y, int val){
		return query(1, 0, sz, x, y, val);
	}
	int ask(int i, int s, int e, int x, int y){
		if(e < x || y < s) return 0;
		if(x <= s && e <= y) return dat[i];
		int m = (s + e) / 2;
		return gcd(ask(i << 1, s, m, x, y), ask(i << 1 | 1, m + 1, e, x, y));
	}
	int ask(int x, int y){
		if(y < x) return 0;
		return ask(1, 0, sz, x, y);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	seg tree(n + 1);
	rep(i, n) cin >> a[i], tree.update(i, a[i]);
	int q;
	cin >> q;
	rep(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int l, r, x;
			cin >> l >> r >> x; l--; r--;
			int id = tree.query(l, r, x);
			int owo = gcd(tree.ask(l, id - 1), tree.ask(id + 1, r));
			if(id == -1 || owo % x == 0) cout << "YES\n";
			else cout << "NO\n";
		}
		else{
			int ind, y;
			cin >> ind >> y; ind--;
			tree.update(ind, y);
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
