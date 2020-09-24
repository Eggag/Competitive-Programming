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

int m, n;
int a[mxN], b[mxN], c[mxN], d[mxN];
vi comp;

int find(int nm){
	return lower_bound(comp.begin(), comp.end(), nm) - comp.begin();
}

struct seg{
	ll dat[1 << 20];
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 20); i++){
			dat[i] = 1e18;
		}
	}
	void update(int i, int s, int e, int x, ll v){
		if(s == e){
			dat[i] = min(dat[i], v);
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
	cin >> m >> n;
	rep(i, m){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		comp.pb(c[i]), comp.pb(b[i]), comp.pb(c[i]);
	}
	comp.push_back(1);
	comp.push_back(n);
	sort(all(comp));
	comp.erase(unique(all(comp)), comp.end());
	int tot = comp.size() - 1;
	seg lseg(tot), rseg(tot);
	rep(i, m){
		a[i] = find(a[i]);
		b[i] = find(b[i]);
		c[i] = find(c[i]);
	}
	lseg.update(0, 0);
	rseg.update(tot, 0);
	ll ans = 1e18;
	rep(i, m){
		ans = min(ans, lseg.query(a[i], b[i]) + rseg.query(a[i], b[i]) + d[i]);
		lseg.update(c[i], lseg.query(a[i], b[i]) + d[i]);
		rseg.update(c[i], rseg.query(a[i], b[i]) + d[i]);
	}
	cout << (ans == 1e18 ? -1 : ans) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
