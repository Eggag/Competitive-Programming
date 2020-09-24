#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<bool> prime;
vector<ll> primes;

void sieve(ll n){
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
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	sieve(50);
	int cnt = 0;
	rep(i, primes.size()){
		cout << primes[i] << endl;
		string ans;
		cin >> ans;
		if(ans == "yes") cnt++;
	}
	//check 2 * 2, 3 * 3, 5 * 5, 7 * 7
	//we would think they are primes because of one prime divisor
	vi a = {2, 3, 5, 7};
	rep(i, 4){
		cout << a[i] * a[i] << endl;
		string ans;
		cin >> ans;
		if(ans == "yes") cnt++;
	}
	if(cnt <= 1) cout << "prime" << endl;
	else cout << "composite" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
