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

int ans = 1e9;

void solve(int n, int cnt){
	if(cnt == 2){
		assert(n >= 3);
		ans = min(n, ans);
		return;
	}
	vi div;
	vi divp;
	for(int i = 1; (i * i) <= n; i++){
		if(n % i == 0){
			if(i != n){
				div.pb(i);
				if(prime[i]) divp.pb(i);
			}
			if((n / i) != i && (n / i) != n){
				div.pb(n / i);
				if(prime[n / i]) divp.pb(n / i);
			}
		}
	}
	rep(i, divp.size()) repn(j, 1, 101){
		if(j > divp[i]) break;
		solve(n - divp[i] + j, cnt + 1);
	}
	solve(n, cnt + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	sieve(1e6);
	int n;
	cin >> n;
	solve(n, 0);
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
