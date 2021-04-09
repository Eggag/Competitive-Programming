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

int n;
ll a[mxN];
pair<int, ll> s1[4 * mxN];
ll lazy[4 * mxN];

void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s1[id] = mp(l, a[l]);
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	if(s1[id << 1].se < s1[id << 1 | 1].se) s1[id] = s1[id << 1];
	else s1[id] = s1[id << 1 | 1];
}

void down(int id, int l, int r){
	if(lazy[id]){
		s1[id].se -= 1LL * lazy[id];
		if((r - l) > 1){
			lazy[id << 1] += lazy[id];
			lazy[(id << 1) + 1] += lazy[id];
		}
	}
	lazy[id] = 0;
}

void increase(int x, int y, ll u, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] += u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, id << 1 | 1, mid, r);
	if(s1[id << 1].se < s1[id << 1 | 1].se) s1[id] = s1[id << 1];
	else s1[id] = s1[id << 1 | 1];
}

pair<int, ll> minQ(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return mp(-1, 1e18);
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	pair<int, ll> a = minQ(x, y, id << 1, l, mid);
	pair<int, ll> b = minQ(x, y, id << 1 | 1, mid, r);
	if(a.se < b.se) return a;
	return b;
}

ll solve(int l, int r){
	if(l > r) return 0;
	pair<int, ll> mn = minQ(l, r + 1);
	increase(l, r + 1, mn.se);
	return (mn.se ? 1 : 0) + solve(l, mn.fi - 1) + solve(mn.fi + 1, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> a[i];
	build();
	cout << solve(0, n - 1) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
