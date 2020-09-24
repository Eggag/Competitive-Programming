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
ll a[mxN], s[4 * mxN], s1[4 * mxN], lazy[4 * mxN];

void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s[id] = a[l];
		s1[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build((id << 1) + 1, mid, r);
	s[id] = (s[id << 1] + s[(id << 1) + 1]);
	s1[id] = min(s1[id << 1], s1[(id << 1) + 1]);
}
 
void down(int id, int l, int r){
	if(lazy[id]){
		s[id] += 1LL * lazy[id] * (r - l);
		s1[id] += 1LL * lazy[id];
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
	increase(x, y, u, (id << 1) + 1, mid, r);
	s[id] = s[id << 1] + s[(id << 1) + 1];
	s1[id] = min(s1[id << 1], s1[(id << 1) + 1]);
}
 
ll sum(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}

ll minQ(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return 1e18;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return min(minQ(x, y, id * 2, l, mid), minQ(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	int q;
	cin >> n >> q;
	rep(i, n) cin >> a[i];
	build();
	rep(i, q){
		char t;
		cin >> t;
		int l, r;
		cin >> l >> r;
		if(t == 'M') cout << minQ(l - 1, r) << '\n';
		if(t == 'P'){
			ll c;
			cin >> c;
			increase(l - 1, r, c);
		}
		if(t == 'S') cout << sum(l - 1, r) << '\n';
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
