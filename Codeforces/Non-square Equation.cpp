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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int sum_dig(int n){
	int ret = 0;
	while(n){
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

ll mysqrt(ll x){
	ll l = 0, r = 1e10;
	while ((r - l) > 1){
		ll m = (l + r) / 2;
		if((m * (ll)(m)) <= x) l = m;
		else r = m;
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	ll ans = 1e18;
	for(ll i = 1; i <= 100; i++){
		ll d = sq(i) - 4 * (-n);
		if(d < 0) continue;
		ll s = mysqrt(d);
		if(sq(s) != d) continue;
		ll one = -i + s;
		if(one % 2 == 0 && sum_dig(one / 2) == i && one > 0) ans = min(ans, one / 2);
		ll two = -i - s;
		if(two % 2 == 0 && sum_dig(two / 2) == i && two > 0) ans = min(ans, two / 2);
	}
	if(ans == 1e18) ans = -1;
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
