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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll k;
ll lazy[4 * mxN];
pair<ll, int> s[4 * mxN];
vector<pair<int, ll>> en[mxN];

void build(int id = 1, int l = 0, int r = mxN){
	if((r - l) < 2){
		s[id] = mp((ll)(1LL * -k * (l + 1)), l);
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build((id << 1) + 1, mid, r);
	s[id] = max(s[id << 1], s[(id << 1) + 1]);
}
 
void down(int id, int l, int r){
	if(lazy[id]){
		s[id].fi += 1LL * lazy[id];
		if((r - l) > 1){
			lazy[id << 1] += lazy[id];
			lazy[(id << 1) + 1] += lazy[id];
		}
	}
	lazy[id] = 0;
}
 
void increase(int x, int y, ll u, int id = 1, int l = 0, int r = mxN){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] += u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, (id << 1) + 1, mid, r);
	s[id] = max(s[id << 1], s[(id << 1) + 1]);
}
 
pair<ll, int> maxQ(int x, int y, int id = 1, int l = 0, int r = mxN){
	down(id, l, r);
	if(x >= r || l >= y) return mp(-4e18, -1);
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return max(maxQ(x, y, id * 2, l, mid), maxQ(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n >> k;
	build();
	vector<pi> p1;
	vector<ll> v(n);
	rep(i, n){
		int l, r;
		ll p;
		cin >> l >> r >> p;
		l--, r--;
		p1.pb(mp(l, r));
		v[i] = p;
		increase(r, mxN - 1, p);
		en[l].pb(mp(r, p));
	}
	ll bst = -4e18;
	int le = -1, ri = -1;
	rep(i, mxN - 4){
		pair<ll, int> cr = maxQ(i, mxN - 1);
		cr.fi = cr.fi - (!i ? 0 : maxQ(i - 1, i).fi);
		if(cr.fi > bst){
			bst = cr.fi;
			le = i, ri = cr.se;
		}
		for(pair<int, ll> x : en[i]) increase(x.fi, mxN - 1, -x.se);
	}
	if(bst <= 0){
		cout << 0 << '\n';
		return 0;
	}
	vi ans;
	ll sum = 0LL;
	rep(i, n) if(p1[i].fi >= le && p1[i].se <= ri) ans.pb(i), sum += v[i];
	assert((sum - (k * (ll)(ri - le + 1))) == bst);
	assert(ri >= le);
	cout << bst << " " << le + 1 << " " << ri + 1 << " " << (int)(ans.size()) << '\n';
	for(int x : ans) cout << x + 1 << " ";
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
