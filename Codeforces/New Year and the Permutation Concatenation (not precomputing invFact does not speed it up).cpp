#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll fact[1000005];

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
	ll n;
	cin >> n;
	fact[0] = 1;
	for(ll i = 1; i < 1000005; i++){
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
	}
	ll ans = fact[n];
	if(n <= 2){
		cout << fact[n] << endl;
		return 0;
	}
	if(n == 3){
		cout << 9 << endl;
		return 0;
	}
	vector<pair<ll, ll>> st = {mp(3, 3)};
	ll add = 5;
	for(ll i = 3; i < n; i++) st.pb(mp(st[st.size() - 1].fi + add, i + 1)), add += 2;
	reverse(all(st));
	for(ll i = 1LL; i < (n - 1); i++){
		ll en = st[i - 1].se + (i - 1);
		ll cur = i;
		(cur *= ((1LL * fact[en] * inv(fact[st[i - 1].se])) + MOD) % MOD) %= MOD;
		(cur *= ((1LL * st[i - 1].fi) + MOD) % MOD) %= MOD;
		(ans += (cur + MOD)) %= MOD;
	}
	cout << ans % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
