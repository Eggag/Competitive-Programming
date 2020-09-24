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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	unordered_map<int, int> superNum;
	rep(i, n){
		int num = a[i];
		for(int j = 2; (j * j) <= num; j++){
			int cnt = 0;
			while(num % j == 0){
				num /= j;
				cnt++;
			}
			if(cnt) superNum[j] = max(superNum[j], cnt);
		}
		if(num > 1) superNum[num] = max(superNum[num], 1);
	}
	ll ans = 0;
	rep(i, n){
		int num = a[i];
		ll cur = 1LL;
		for(int j = 2; (j * j) <= num; j++) if(num % j == 0){
			int cnt = 0;
			while(num % j == 0){
				num /= j;
				cnt++;
			}
			(cur *= mypow(j, superNum[j] - cnt)) %= MOD;
		}
		if(num > 1){
			(cur *= mypow(num, superNum[num] - 1)) %= MOD;
		}
		for(pi x : superNum){
			if(a[i] % x.fi != 0){
				(cur *= mypow(x.fi, x.se)) %= MOD;
			}
		}
		ans += cur;
	}
	cout << (ans % MOD) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
