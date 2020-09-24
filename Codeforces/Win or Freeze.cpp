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

bool prime(ll num){
	for(ll i = 2; i <= sqrt(num); i++){
		if(num % i == 0) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	ll n1 = n;
	vector<ll> div; //prime factorization of n
	if(prime(n) || n == 1){
		cout << 1 << endl << 0 << endl;
	}
	else{
		for(ll i = 2; i * i <= n1; i++){
			while(n1 % i == 0){
				div.pb(i);
				n1 /= i;
			}
		}
		if(n1 > 1) div.pb(n1);
		if(div.size() <= 2){
			cout << 2 << endl;
		}
		else{
			cout << 1 << endl << div[0] * div[1] << endl;
		}
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
