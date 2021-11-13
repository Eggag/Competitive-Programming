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
	int n, L, R;
	cin >> n >> L >> R;
	ll mn = min(abs(L - 1), R - n);
	ll ans = (C(n, n / 2) * mn) % MOD;
	if(n & 1) (ans *= 2) %= MOD;
	int l = 1, r = n;
	int l1 = 1, r1 = n;
	ll ans1 = 0LL;
	if(n % 2 == 0){
		repn(i, mn + 1, mn + 1 + n + 1){
			if(1 - i < L) l++;
			if(r1 + i > R) r1--;
			int l2 = max(l, l1), r2 = min(r, r1);
			if(r2 < (l2 - 1)) break;
			else{
				ll sz = r2 - l2 + 1;
				ll lft = max((n / 2) - (l2 - l1), (n / 2) - (r - r2));
				(ans1 += C(sz, lft)) %= MOD;
			}
		}
	}
	else{
		repn(i, mn + 1, mn + 1 + n + 1){
			if(1 - i < L) l++;
			if(r1 + i > R) r1--;
			int l2 = max(l, l1), r2 = min(r, r1);
			if(r2 < (l2 - 1)) break;
			else{
				ll sz = r2 - l2 + 1;
				ll a = ((n + 1) / 2) - (l2 - l1);
				ll b = (n / 2) - (r - r2);
				(ans1 += C(sz, max(a, b))) %= MOD;
			}
		}
		l = 1, r = n;
		l1 = 1, r1 = n;
		repn(i, mn + 1, mn + 1 + n + 1){
			if(1 - i < L) l++;
			if(r1 + i > R) r1--;
			int l2 = max(l, l1), r2 = min(r, r1);
			if(r2 < (l2 - 1)) break;
			else{
				ll sz = r2 - l2 + 1;
				ll a = (n / 2) - (l2 - l1);
				ll b = ((n + 1) / 2) - (r - r2);
				(ans1 += C(sz, max(a, b))) %= MOD;
			}
		}
	}
	(ans += ans1) %= MOD;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	invFact[0] = 1;
	fact[0] = 1;
	for(ll i = 1LL; i < mxN; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
	for(ll i = mxN - 1; i >= 0LL; i--){
		if(i == (mxN - 1)) invFact[i] = inv(fact[i]);
		else invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
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
