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

int n;
int a[mxN], s[4 * mxN], lazy[4 * mxN];

void build(int id = 1, int l = 0, int r = n - 1){
	if((r - l) < 1){
		s[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build((id << 1) + 1, mid + 1, r);
	s[id] = (s[id << 1] + s[(id << 1) + 1]);
}
 
void down(int id, int l, int r){
	if(~lazy[id]){
		s[id] = lazy[id] * (r - l + 1);
		if((r - l) > 0){
			lazy[id << 1] = lazy[id];
			lazy[(id << 1) + 1] = lazy[id];
		}
	}
	lazy[id] = -1;
}
 
void increase(int x, int y, int u, int id = 1, int l = 0, int r = n - 1){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] = u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, (id << 1) + 1, mid + 1, r);
	s[id] = s[id << 1] + s[(id << 1) + 1];
}
 
int sum(int x, int y, int id = 1, int l = 0, int r = n - 1){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid + 1, r));
}

void solve(){
	int q;
	cin >> n >> q;
	string s1, f;
	cin >> s1 >> f;
	vector<pi> p(q);
	rep(i, 4 * n) lazy[i] = -1, s[i] = 0;
	rep(i, q) cin >> p[i].fi >> p[i].se;
	rep(i, n) a[i] = (f[i] == '1' ? 1 : 0);
	build();
	for(int i = q - 1; i >= 0; i--){
		int sm = sum(p[i].fi - 1, p[i].se - 1);
		if(sm == (p[i].se - p[i].fi + 1) / 2 && (p[i].se - p[i].fi + 1) % 2 == 0){
			cout << "NO" << '\n';
			return;
		}
		if(sm > (p[i].se - p[i].fi + 1) / 2) increase(p[i].fi - 1, p[i].se - 1, 1);
		else increase(p[i].fi - 1, p[i].se - 1, 0);
	}
	rep(i, n){
		int v = (s1[i] == '1' ? 1 : 0);
		if(sum(i, i) != v){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
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
