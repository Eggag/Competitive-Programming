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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll x[mxN];
ll cnt[65];
ll p2[105];

void solve(){
	int n;
	cin >> n;
	rep(i, n) cin >> x[i];
	rep(i, 65) cnt[i] = 0LL;
	rep(i, n){
		for(int j = 61; j >= 0; j--) if(x[i] & (1LL << j)){
			cnt[j]++;
		}
	}
	ll ans = 0LL;
	rep(i, n){
		ll f = 0LL;
		rep(l, 62){
			ll nm = 0LL;
			if(x[i] & (1LL << l)) nm = n;
			else nm = cnt[l];
			(f += (nm * p2[l]) % MOD) %= MOD;
		}
		ll tot = 0LL;
		rep(k, 62) if(x[i] & (1LL << k)){
			ll lh = (p2[k] * cnt[k]) % MOD;
			(tot += lh) %= MOD;
		}
		(ans += (f * tot) % MOD) %= MOD;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	p2[0] = 1LL;
	repn(i, 1, 100) p2[i] = (p2[i - 1] * 2) % MOD;
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
