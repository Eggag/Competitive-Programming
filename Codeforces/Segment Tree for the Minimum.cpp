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

struct seg{
	ll dat[1 << 18];
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 18); i++){
			dat[i] = 1e18;
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
		dat[i] = min(dat[i << 1], dat[i << 1 | 1]);
	}
	void update(int x, ll v){
		update(1, 0, sz, x, v);
	}
	ll query(int i, int s, int e, int x, int y){
		if(e < x || y < s) return 1e18;
		if(x <= s && e <= y) return dat[i];
		int m = (s + e) / 2;
		return min(query(i << 1, s, m, x, y), query(i << 1 | 1, m + 1, e, x, y));
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
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	seg tree(n);
	rep(i, n) tree.update(i, a[i]);
	rep(i, m){
		int t;
		cin >> t;
		if(t == 1){
			int x, y;
			cin >> x >> y;
			tree.update(x, y);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << tree.query(l, r - 1) << '\n';
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
