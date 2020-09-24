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

int a[505][505];

vector<bool> prime;
vi primes;

void sieve(int n){
	prime.assign(n + 1, 1);
	prime[1] = false;
	for(ll i = 2; i <= n; i++){
		if(prime[i]){
			primes.pb(i);
			for(ll j = i * 2; j <= n; j += i){
				prime[j] = false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> a[i][j];
	sieve(1e6);
	int ans = 1e9;
	rep(i, n){
		int cur = 0;
		rep(j, m){
			int pos = ub(all(primes), a[i][j]) - primes.begin();
			if(pos) if(primes[pos - 1] >= a[i][j]) pos--;
			if(a[i][j] > primes[pos]) pos++;
			cur += (primes[pos] - a[i][j]);
		}
		ans = min(ans, cur);
	}
	rep(j, m){
		int cur = 0;
		rep(i, n){
			int pos = ub(all(primes), a[i][j]) - primes.begin();
			if(pos) if(primes[pos - 1] >= a[i][j]) pos--;
			if(a[i][j] > primes[pos]) pos++;
			cur += (primes[pos] - a[i][j]);
		}
		ans = min(ans, cur);
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
