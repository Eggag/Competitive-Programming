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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n, m, a;

ll mypow(ll b, ll p){
	if(p == 0) return 1;
	if(p == 1) return (b % MOD);
	if(p & 1) return ((b % MOD) * (mypow(b, p - 1) % MOD)) % MOD;
	ll x = mypow(b, p / 2) % MOD;
	return (x * x) % MOD;
}

ll inv(ll num){
	return mypow(num, MOD - 2);
}

ll cnt(ll len){
	ll ret = (mypow(a, len * 2) + mypow(a, len)) % MOD;
	return (ret * inv(2)) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> a;
	vector<ll> b(m);
	rep(i, m) cin >> b[i];
	ll ans = mypow(a, n - (b[m - 1] * 2));
	(ans *= cnt(b[0])) %= MOD;
	repn(i, 1, m) (ans *= cnt(b[i] - b[i - 1])) %= MOD;
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
