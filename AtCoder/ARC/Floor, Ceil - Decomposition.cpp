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
const int MOD = 998244353;

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
	ll x;
	cin >> x;
	if(x <= 3){
		cout << x << '\n';
		return 0;
	}
	ll x1 = x;
	ll cnt = 0;
	while(x > 3){
		cnt++;
		x /= 2;
	}
	if(x1 >= (3 * (1LL << cnt))){
		ll nm4 = x1 - (3 * (1LL << cnt));
		ll nm3 = (1LL << cnt) - nm4;
		cout << (mypow(4, nm4) * mypow(3, nm3)) % MOD << '\n';
	}
	else{
		ll cnt1 = 0;
		ll x2 = x1;
		while(x2 > 2){
			cnt1++;
			x2 /= 2;
		}
		ll nm3 = x1 - (2 * (1LL << cnt1));
		ll nm2 = (1LL << cnt1) - nm3;
		cout << (mypow(2, nm2) * mypow(3, nm3)) % MOD << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
