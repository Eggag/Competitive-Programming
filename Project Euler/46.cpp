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

vector<int> primes;
vector<bool> prime(1e6 + 5, 1);

void sieve(){
	for(int i = 2; i <= 1e6; i++) if(prime[i]){
		primes.pb(i);
		for(int j = i + i; j <= 1e6; j += i) prime[j] = 0;
	}
}

bool check(int num){
	int s = sqrt(num);
	if(sq(s) != num) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	sieve();
	int ind = 0;
	for(int i = 1; i <= 1e6; i++){
		if(!prime[i]){
			if(!(i % 2)) continue;
			int f = 1;
			rep(j, ind){
				int num = i - primes[j];
				num /= 2;
				if(check(num)){
					f = 0;
					break;
				}
			}
			if(f){
				cout << i << endl;
				return 0;
			}
		}
		else ind++;	
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
