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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll fact[100005];

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

ll choose(ll a, ll b){
	ll ret = fact[a] * inv((fact[b] * fact[a - b]) % MOD);
	return (ret % MOD);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	fact[0] = 1LL;
	for(ll i = 1; i < 100005; i++) fact[i] = ((fact[i - 1] * i) + MOD) % MOD;
	sort(all(a));
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		if(i >= (k - 1)){
			ans = (ans + (((a[i] * choose(i, k - 1)) + MOD) % MOD) + MOD) % MOD;
		}
	}
	for(ll i = 0; i < n; i++){
		if(i <= (n - k)){
			ans = (ans - (((a[i] * choose(n - i - 1, k - 1) + MOD) % MOD)) + MOD) % MOD;
		}
	}
	cout << (ans + MOD) % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
