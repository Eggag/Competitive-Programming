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
const int MOD = 1e9 + 7;
const int mxN = 2e5 + 5;

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

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	ll ans = 0LL;
	rep(i, n){
		auto nxt = lb(all(a), a[i] + k + 1);
		int ind = nxt - a.begin();
		ind--;
		(ans += C(ind - i, m - 1)) %= MOD;
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	fact[0] = 1;
	invFact[0] = 1;
	for(ll i = 1; i < mxN; i++){
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
		invFact[i] = inv(fact[i]);
	}
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
