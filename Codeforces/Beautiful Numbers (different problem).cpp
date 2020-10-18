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

ll fact[9000005];

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

ll C(ll n, ll r){
	if(r > n) return 0;
	ll ret = fact[n];
	ret = ((ret * inv(fact[n - r])) + MOD) % MOD;
	ret = ((ret * inv(fact[r])) + MOD) % MOD;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int a, b, n;
	cin >> a >> b >> n;
	fact[0] = 1;
	for(ll i = 1; i < 9000005; i++){
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
	}
	if(b > a) swap(a, b); //a is larger
	vi good;
	repn(i, 1, 9e6){
		int cur = i;
		int f = 1;
		while(cur){
			if(cur % 10 != a && cur % 10 != b) f = 0;
			cur /= 10;
		}
		if(f && i) good.pb(i);
	}
	int ans = 0;
	rep(i, good.size()){
		for(int j = 0; j <= good[i]; j += a){
			int rem = good[i] - j;
			if(rem % b == 0){
				int x = j / a, y = rem / b;
				if(x + y == n) (ans += C(x + y, x)) %= MOD;
			}
		}
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