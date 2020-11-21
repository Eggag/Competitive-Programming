#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m, k, k1;
	cin >> n >> m >> k;
	k1 = k;
	if(((2 * n * m) % k != 0)){
		cout << "NO" << endl;
		return 0;
	}
	ll a = 2 * m, b = n;
	for(ll i = 2; (i * i) <= k; i++){
		while(k % i == 0){
			if(a % i == 0) a /= i;
			else b /= i;
			k /= i;
		}
	}
	if(k > 1){
		if(a % k == 0) a /= k;
		else b /= k;
	}
	if(a > m){
		a = m, b = 2 * n;
		k = k1;
		for(ll i = 2; (i * i) <= k; i++){
			while(k % i == 0){
				if(b % i == 0) b /= i;
				else a /= i;
				k /= i;
			}
		}
		if(k > 1){
			if(b % k == 0) b /= k;
			else a /= k;
		}
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << 0 << " " << a << endl;
		cout << b << " " << 0 << endl;
	}
	else{
		cout << "YES" << endl;
		cout << "0 0" << endl;
		cout << 0 << " " << a << endl;
		cout << b << " " << 0 << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
