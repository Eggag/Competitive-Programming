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

vector<ll> primes;
vector<bool> prime(1e6 + 5, 1);

void sieve(){
	for(ll i = 2; i <= 1e6; i++) if(prime[i]){
		primes.pb(i);
		for(ll j = i + i; j <= 1e6; j += i) prime[j] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	sieve();
	vector<ll> sum((int)(primes.size()));
	sum[0] = primes[0];
	repn(i, 1, primes.size()) sum[i] = sum[i - 1] + primes[i];
	ll mx = 0;
	int best = 0;
	rep(i, primes.size()) repn(j, i + 1, primes.size()){
		ll cur = sum[j] - sum[i];
		if(cur > 1e6) break;
		if(prime[cur] && (j - i + 1) > best) mx = cur, best = j - i + 1;
	}
	rep(i, primes.size()){
		if(sum[i] > 1e6) break;
		if(prime[sum[i]] && (i + 1) > best) mx = sum[i], best = i + 1;
	}
	cout << mx << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
