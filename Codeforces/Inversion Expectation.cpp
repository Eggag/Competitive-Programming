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
const int MOD = 998244353;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll fact[mxN];
ll invFact[mxN];

ll C(ll n, ll r){
	if(r > n) return 0;
	ll ret = fact[n];
	ret = ((ret * invFact[n - r]) + MOD) % MOD;
	return ret;
}

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1) % MOD)) % MOD;
	ll x = mypow(a, p / 2) % MOD;
	return (x * x) % MOD;
}

ll inv(ll base){
	return mypow(base, MOD - 2);
}

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
};

int vis[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	invFact[0] = 1;
	fact[0] = 1;
	for(ll i = 1LL; i < mxN; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
	for(ll i = mxN - 1; i >= 0LL; i--){
		if(i == (mxN - 1)) invFact[i] = inv(fact[i]);
		else invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
	}
	vi p(n), a;
	rep(i, n) cin >> p[i], vis[p[i]] = 1;
	repn(i, 1, n + 1) if(!vis[i]) a.pb(i);
	ll m = a.size(), m1 = m;
	ll tot = 0LL;
	//we consider 4 cases
	//(1, 1), (1, -1), (-1, 1), (1, 1)
	rep(i, n){
		//(1, -1) and (-1, 1)
		if(~p[i]){
			auto it = lb(all(a), p[i]);
			if(it != a.begin()){
				it--;
				ll num = (ll)(it - a.begin()) + 1;
				(tot += (1LL * m1 * num) % MOD) %= MOD;
				(tot += (1LL * (m - m1) * (m - num)) % MOD) %= MOD;
			}
			else (tot += (1LL * (m - m1) * m) % MOD) %= MOD;
		}
		else m1--;
	}
	(tot *= fact[m - 1]) %= MOD;
	//(-1, -1)
	ll tot1 = (fact[m] * m) % MOD;
	(tot1 *= ((m - 1) * inv(4)) % MOD) %= MOD;
	//(1, 1)
	BIT<ll> bit;
	ll tot2 = 0LL, nm = 0LL;
	rep(i, n) if(~p[i]){
		(tot2 += (ll)(1LL * (nm - bit.query(p[i])))) %= MOD;
		nm++;
		bit.update(p[i], 1);
	}
	(tot2 *= fact[m]) %= MOD;
	cout << (((tot + tot1 + tot2) % MOD) * inv(fact[m])) % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
