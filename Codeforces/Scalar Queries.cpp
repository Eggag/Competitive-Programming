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
const int mxN = 5e5 + 5;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(mxN, 0);
	}
	void update(int ind, T delta){
		for(; ind < mxN; ind = ind | (ind + 1)){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind >= 0; ind = (ind & (ind + 1)) - 1){
			sum += bit[ind];
		}
		return sum;
	}
	T query2(int ind){
		return query(mxN - 1) - query(ind);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<pair<ll, int>> c(n);
	rep(i, n) cin >> a[i], c[i] = {a[i], i};
	sort(all(c));
	BIT<ll> bit, bit1;
	vector<ll> l(n), r(n);
	rep(i, n){
		l[i] = bit.query(c[i].se) % MOD;
		r[i] = bit1.query2(c[i].se) % MOD;
		bit.update(c[i].se, c[i].se + 1);
		bit1.update(c[i].se, n - c[i].se);
	}
	ll ans = 0LL;
	rep(i, n){
		ll tmp = (1LL * (ll)(n - c[i].se) * l[i] + (ll)(c[i].se + 1) * r[i]) % MOD;
		ll cur = (c[i].fi * tmp) % MOD;
		(ans += cur) %= MOD;
	}
	rep(i, n){
		ll cur = (1LL * a[i] * ((1LL * (ll)(i + 1) * (ll)(n - i)) % MOD)) % MOD;
		(ans += cur) %= MOD;
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
