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
const int MOD = 998244353;
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll fact[mxN];
ll invFact[mxN];

ll C(ll n, ll r){
	if(r > n) return 0;
	ll ret = fact[n];
	ret = ((ret * invFact[n - r]) + MOD) % MOD;
	ret = ((ret * invFact[r]) + MOD) % MOD;
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll d;
	cin >> d;
	ll cr = d;
	vector<ll> f;
	for(ll i = 2; (i * i) <= cr; i++){
		int cnt = 0;
		while(cr % i == 0) cr /= i, cnt++;
		if(cnt) f.pb(i);
	}
	if(cr > 1) f.pb(cr);
	invFact[0] = 1;
	fact[0] = 1;
	for(ll i = 1LL; i < mxN; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
	for(ll i = mxN - 1; i >= 0LL; i--){
		if(i == (mxN - 1)) invFact[i] = inv(fact[i]);
		else invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
	}
	int q;
	cin >> q;
	rep(j, q){
		ll u, v;
		cin >> u >> v;
		if(u < v) swap(u, v);
		ll ans = 1LL;
		ll cnt = 0LL, cnt1 = 0LL;
		rep(i, f.size()){
			int cnt2 = 0, cnt3 = 0;
			while(u % f[i] == 0) cnt2++, u /= f[i];
			while(v % f[i] == 0) cnt3++, v /= f[i];
			if(cnt2 > cnt3){
				ll n = cnt2 - cnt3, k = cnt + 1;
				(ans *= C(n + k - 1, k - 1)) %= MOD;
				cnt += n;
			}
			if(cnt2 < cnt3){
				ll n = cnt3 - cnt2, k = cnt1 + 1;
				(ans *= C(n + k - 1, k - 1)) %= MOD;
				cnt1 += n;
			}
		}
		cout << ans << '\n';
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
