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
#define inf 0x3f3f3f3f
const int logn = 22;
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, p;
int s1[4 * mxN], lazy[4 * mxN];

void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s1[id] = p;
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build((id << 1) + 1, mid, r);
	s1[id] = min(s1[id << 1], s1[(id << 1) + 1]);
}

void down(int id, int l, int r){
	if(lazy[id] != inf){
		s1[id] = min(lazy[id], s1[id]);
		if((r - l) > 1){
			lazy[id << 1] = min(lazy[id << 1], lazy[id]);
			lazy[id << 1 | 1] = min(lazy[id << 1 | 1], lazy[id]);
		}
	}
	lazy[id] = inf;
}

void increase(int x, int y, int u, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] = min(lazy[id], u);
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, (id << 1) + 1, mid, r);
	s1[id] = min(s1[id << 1], s1[(id << 1) + 1]);
}

int minQ(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return inf;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return min(minQ(x, y, id * 2, l, mid), minQ(x, y, id * 2 + 1, mid, r));
}


int gc[logn][mxN];
 
int GCD(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return gcd(gc[t][l], gc[t][r - (1 << t)]);
}

void solve(){
	cin >> n >> p;
	vector<pi> a(n);
	rep(i, n) cin >> a[i].fi, a[i].se = i;
	build();
	rep(i, 4 * n) lazy[i] = inf;
	set<int> st;
	rep(i, n) gc[0][i] = a[i].fi;
	sort(all(a));
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) <= n; i++){
			gc[l + 1][i] = gcd(gc[l][i], gc[l][i + (1 << l)]);
		}
	}
	rep(i, n){
		int l = 0, r = n - 1;
		auto it = st.lb(a[i].se);
		if(it != st.end()) r = *it - 1;
		if(it != st.begin()){
			it--;
			l = *it + 1;
		}
		int l1 = a[i].se, r1 = r;
		while(l1 < r1){
			int mid1 = (l1 + r1 + 1) / 2;
			if(GCD(a[i].se, mid1 + 1) == a[i].fi) l1 = mid1;
			else r1 = mid1 - 1;
		}
		int l2 = l, r2 = a[i].se;
		while(l2 < r2){
			int mid2 = (l2 + r2) / 2;
			if(GCD(mid2, a[i].se + 1) == a[i].fi) r2 = mid2;
			else l2 = mid2 + 1;;
		}
		if(l2 < l1) increase(l2, l1, a[i].fi);
		st.insert(a[i].se);
	}
	ll ans = 0LL;
	rep(i, n - 1) ans += minQ(i, i + 1);
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
