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
 
ll dp[355][355][2]; //[index][tot][already have one happy]

ll fact[355];
ll invFact[355];

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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n + 2) rep(j, n + 2) rep(k, 2) dp[i][j][k] = 0LL;
	fact[0] = 1LL;
	invFact[0] = 1LL;
	for(ll i = 1LL; i < 355; i++){
		fact[i] = (1LL * fact[i - 1] * i) % MOD;
		invFact[i] = inv(fact[i]);
	}
	dp[1][1][1] = n;
	rep(i, n + 1) if(i != 1) dp[1][i][0] = C(n, i);
	repn(i, 2, n + 1){
		rep(j, n + 1){
			rep(k, n + 1) if((j + k) <= n){
				if(k == i){
					dp[i][j + k][1] = (dp[i][j + k][1] + (((dp[i - 1][j][1] + dp[i - 1][j][0]) % MOD) * C(n - j, k)) % MOD) % MOD;
				}
				else{
					dp[i][j + k][1] = (dp[i][j + k][1] + ((dp[i - 1][j][1] * C(n - j, k)) % MOD)) % MOD;
					dp[i][j + k][0] = (dp[i][j + k][0] + ((dp[i - 1][j][0] * C(n - j, k)) % MOD)) % MOD;
				}
			}
		}
	}
	cout <<  dp[n][n][1] % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
