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
vector<int> primes;

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

int mypow(int a, int p){
	if(p == 0) return 1;
	if(p == 1) return (a);
	if(p & 1) return ((a) * (mypow(a, p - 1)));
	int x = mypow(a, p / 2);
	return (x * x);
}

bool check(int num){
	int num1 = num;
	while(num1 > 9){
		num1 /= 10;
		if(!prime[num1]) return 0;
	}
	num1 = num;
	string s = to_string(num1);
	rep(i, s.size() - 1){
		num1 -= (s[i] - '0') * mypow(10, (int)s.size() - i - 1);
		if(!prime[num1]) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	sieve(1e6);	
	int ans = 0;
	int cnt = 0;
	rep(i, primes.size()){
		if(check(primes[i]) && primes[i] > 10) cnt++, ans += primes[i], debug(primes[i]);
		if(cnt == 11) break;
	}
	debug(ans);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
