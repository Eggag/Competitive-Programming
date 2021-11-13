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

ll p;

ll vv(ll num){
	if(!num) return 0;
	int cnt = 0;
	while(num % p == 0) num /= p, cnt++;
	return cnt;
}

ll mypow(ll a, ll pp){
	if(pp <= 0) return 1LL;
	if(pp & 1) return a * mypow(a, pp - 1);
	ll x = mypow(a, pp / 2);
	return x * x;
}

struct seg{
	ll dat[1 << 20];
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 20); i++){
			dat[i] = 0LL;
		}
	}
	void update(int i, int s, int e, int x, ll v){
		if(s == e){
			dat[i] = vv(v);
			return;
		}
		int m = (s + e) / 2;
		if(x <= m) update(i << 1, s, m, x, v);
		else update(i << 1 | 1, m + 1, e, x, v);
		dat[i] = dat[i << 1] + dat[i << 1 | 1];
	}
	void update(int x, ll v){
		update(1, 0, sz, x, v);
	}
	ll query(int i, int s, int e, int x, int y){
		if(e < x || y < s) return 0;
		if(x <= s && e <= y) return dat[i];
		int m = (s + e) / 2;
		return query(i << 1, s, m, x, y) + query(i << 1 | 1, m + 1, e, x, y);
	}
	ll query(int x, int y){
		return query(1, 0, sz, x, y);
	}
} tree1(mxN), tree2(mxN), tree3(mxN), tree4(mxN);

void solve(){
	int n, q;
	cin >> n >> q >> p;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n){
		int pos = i;
		ll val = a[i];
		tree1.update(pos, val - (val % p));
		tree2.update(pos, mypow(val, 2) - mypow((val % p), 2));
		tree3.update(pos, mypow(val, 3) - mypow((val % p), 3));
		tree4.update(pos, mypow(val, 4) - mypow((val % p), 4));
	}
	rep(i, q){
		int tp;
		cin >> tp;
		if(tp == 1){
			int pos;
			ll val;
			cin >> pos >> val; pos--;
			tree1.update(pos, val - (val % p));
			tree2.update(pos, mypow(val, 2) - mypow((val % p), 2));
			tree3.update(pos, mypow(val, 3) - mypow((val % p), 3));
			tree4.update(pos, mypow(val, 4) - mypow((val % p), 4));
		}
		else{
			int s, l, r;
			cin >> s >> l >> r;
			l--, r--;
			if(s == 1) cout << tree1.query(l, r);
			if(s == 2) cout << tree2.query(l, r);
			if(s == 3) cout << tree3.query(l, r);
			if(s == 4) cout << tree4.query(l, r);
			if(i != (q - 1)) cout << " ";
			else cout << '\n';
		}
	}
	rep(i, n){
		tree1.update(i, 0);
		tree2.update(i, 0);
		tree3.update(i, 0);
		tree4.update(i, 0);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
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
