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

vector<bool> prime;
vi primes;

void sieve(int n){
	prime.assign(n + 1, 1);
	prime[1] = false;
	for(int i = 2; i <= n; i++){
		if(prime[i]){
			primes.pb(i);
			for(int j = i * 2; j <= n; j += i){
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
	int n;
	cin >> n;
	//all numbers modulo 5 are 1
	sieve(55555);
	vi a;
	rep(i, primes.size()){
		if((int)a.size() == n) break;
		if(primes[i] % 5 == 1) a.pb(primes[i]);
	}
	for(int x : a) cout << x << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
