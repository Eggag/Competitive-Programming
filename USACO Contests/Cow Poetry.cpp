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

ll dp[5005];

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1) % MOD)) % MOD;
	ll x = mypow(a, p / 2) % MOD;
	return (x * x) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	map<int, int> cnt;
	vi s(n), c(n);
	map<int, ll> num;
	rep(i, n) cin >> s[i] >> c[i];
	rep(i, m){
		char ch;
		cin >> ch;
		cnt[ch - 'a']++;
	}
	memset(dp, 0LL, sizeof(dp));
	dp[0] = 1LL;
	repn(i, 1, k + 1){
		rep(j, n) if(s[j] <= i){
			dp[i] = (dp[i] + dp[i - s[j]]) % MOD;
		}
	}
	rep(i, n){
		num[c[i]] = (dp[k - s[i]] + num[c[i]]) % MOD;
	}
	ll ans = 1LL;
	for(pi x : cnt){
		ll cur = 0;
		for(pair<int, ll> y : num){
			cur = (mypow(y.se, x.se) + cur) % MOD;
		}
		ans = (ans * cur) % MOD;
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
