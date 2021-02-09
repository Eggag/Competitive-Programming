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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<bool> prime;
vector<ll> primes;

void sieve(ll mx){
	prime.assign(mx, 0LL);
	for(ll i = 2LL; i <= mx; i++) if(!prime[i]){
		primes.pb(i);
		for(ll j = i * 2; j <= mx; j += i) prime[j] = 1;
	}
}

void solve(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	int f = 1;
	rep(i, primes.size()){
		if(primes[i] > max({b, d})) break;
		ll num = (b / primes[i]) - ((a - 1) / primes[i]);
		ll num1 = (d / primes[i]) - ((c - 1) / primes[i]);
		ll cur = primes[i] * primes[i];
		while(cur <= max(b, d)){
			num += (b / cur) - ((a - 1) / cur);
			num1 += (d / cur) - ((c - 1) / cur);
			cur *= primes[i];
		}
		if(num > num1){
			f = 0;
			break;
		}
	}
	cout << (f ? "DA" : "NE") << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	sieve(10000005);	
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
