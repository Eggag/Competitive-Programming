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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	//(left + x) * (right + y) = left * right + y * left + x * right + x * y
	vector<ll> cntC(n + 1, 0);
	for(int i = n - 1; i >= 0; i--) cntC[i] = cntC[i + 1] + (s[i] == 'C');
	ll ans = 0LL, cntW = 0LL, le = 0LL, ri = 0LL, cntA = 0LL;
	rep(i, n){
		if(s[i] == 'A'){
			(ans += cntW * cntC[i]) %= MOD;
			(le += cntW) %= MOD;
			(ri += cntC[i]) %= MOD;
			cntA++;
		}
		if(s[i] == 'W') cntW++;
	}
	ll ans1 = ans;
	ans = 0LL;
	for(ll i = 0LL; i < k; i++){
		ll x = (cntW * i) % MOD;
		ll y = (cntC[0] * (k - i - 1)) % MOD;
		(ans += ans1 + ((le * y) % MOD) + ((ri * x) % MOD) + ((cntA  * ((x * y) % MOD)) % MOD)) %= MOD;
	}
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
