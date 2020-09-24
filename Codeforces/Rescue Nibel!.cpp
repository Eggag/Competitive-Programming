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
const int mxN = 3e5 + 5;

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

bool cmp(pi a, pi b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se > b.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	fact[0] = 1;
	invFact[0] = 1;
	for(ll i = 1; i < mxN; i++){
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
		invFact[i] = inv(fact[i]);
	}
	int n, k;
	cin >> n >> k;
	vector<pi> p;
	rep(i, n){
		int l, r;
		cin >> l >> r;
		p.pb({l, 1});
		p.pb({r, -1});
	}
	sort(all(p), cmp);
	ll cur = 0LL;
	ll ans = 0LL;
	rep(i, 2 * n){
		if(p[i].se == 1){
			(ans += C(cur, k - 1)) %= MOD;
			cur++;
		}
		else cur--;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
