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

ll k;

ll mypow(ll a, ll p){
	if(p <= 0) return 1LL;
	if(p & 1) return (a * mypow(a, p - 1)) % MOD;
	ll x = mypow(a, p / 2);
	return (x * x) % MOD;
}

ll solve(vi a){
	int n = a.size();
	ll ans = 1LL;
	int l = 0;
	while(l < n && a[l] == -1) l++;
	if(l == n){
		(ans *= (k * mypow(k - 1, l - 1)) % MOD) %= MOD;
		return ans;
	}
	(ans *= mypow(k - 1, l)) %= MOD;
	int r = n - 1, cnt = 0;
	while(r >= 0 && a[r] == -1) r--, cnt++;
	(ans *= mypow(k - 1, cnt)) %= MOD;
	vector<pi> seg;
	int lst = -1;
	repn(i, l, r + 1) if(~a[i]){
		if(~lst && (i - 1) > lst) seg.pb(mp(lst, i));
		lst = i;
	}
	rep(i, seg.size()){
		int le = seg[i].fi, ri = seg[i].se;
		if((ri - le) == 2){
			if(a[le] == a[ri]) (ans *= (k - 1)) %= MOD;
			else (ans *= (k - 2)) %= MOD;
			continue;
		}
		int len = (ri - le) - 1;
		vector<pair<ll, ll>> dp(len, {0LL, 0LL});
		dp[0].fi = 0LL;
		dp[0].se = 1LL;
		repn(i, 1, len - 1){
			(dp[i].fi = dp[i - 1].se * (k - 1)) %= MOD;
			(dp[i].se = (dp[i - 1].se * (k - 2)) + dp[i - 1].fi) %= MOD;
		}
		if(a[le] == a[ri]){
			ll cur = k - 1;
			(cur *= (dp[len - 2].fi + ((dp[len - 2].se * (k - 2)) % MOD)) % MOD) %= MOD;
			(ans *= cur) %= MOD;
		}
		else{
			ll cur = k - 2;
			(cur *= (dp[len - 2].fi + ((dp[len - 2].se * (k - 2)) % MOD)) % MOD) %= MOD;
			ll cur1 = ((dp[len - 2].se * (k - 1)) % MOD);
			(ans *= (cur + cur1) % MOD) %= MOD;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n >> k;
	vi a, b, c(n);
	rep(i, n){
		int x;
		cin >> x;
		c[i] = x;
		if(i & 1) a.pb(x);
		else b.pb(x);
	}
	repn(i, 2, n) if(c[i] == c[i - 2] && ~c[i]){
		cout << "0\n";
		return 0;
	}
	ll ans = (solve(a) * solve(b)) % MOD;
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
