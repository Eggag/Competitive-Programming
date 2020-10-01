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
const int MOD = 998244353;
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, q;
ll s[4 * mxN], lazy[4 * mxN];
ll powt[mxN];

void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s[id] = (powt[l] - (l ? powt[l - 1] : 0) + MOD) % MOD;
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build((id << 1) + 1, mid, r);
	s[id] = (s[id << 1] + s[(id << 1) + 1] + MOD) % MOD;
}
 
void down(int id, int l, int r){
	if(lazy[id]){
		s[id] = (((powt[r - 1] - (l ? powt[l - 1] : 0) + MOD) % MOD) * lazy[id]) % MOD;
		if((r - l) > 1){
			lazy[id << 1] = lazy[id];
			lazy[(id << 1) + 1] = lazy[id];
		}
	}
	lazy[id] = 0;
}
 
void increase(int x, int y, ll u, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] = u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, (id << 1) + 1, mid, r);
	s[id] = (s[id << 1] + s[(id << 1) + 1] + MOD) % MOD;
}
 
ll sum(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id] % MOD;
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r) + MOD) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> q;
	powt[0] = 1;
	ll cur = 1LL;
	repn(i, 1, n){
		powt[i] = (powt[i - 1] + (10 * cur) + MOD) % MOD;
		(cur *= 10) %= MOD;
	}
	build();
	rep(i, q){
		int l, r, d;
		cin >> l >> r >> d;
		l--, r--;
		increase(n - (r + 1), n - l, d);
		cout << sum(0, n) << endl;
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
