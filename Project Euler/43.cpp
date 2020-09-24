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

ll num(vector<ll> n){
	reverse(all(n));
	ll ret = 0;
	ll mult = 1;
	rep(i, n.size()){
		ret += mult * n[i];
		mult *= 10;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vector<ll> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};	
	vector<ll> primes = {2, 3, 5, 7, 11, 13, 17};
	ll sum = 0;
	do{
		if(!a[0]) continue;
		int f = 1;
		repn(i, 1, 8){
			//we do a[i], a[i + 1], a[i + 2]
			ll number = num({a[i], a[i + 1], a[i + 2]});
			if(number % primes[i - 1]){
				f = 0;
				break;
			}
		}
		if(f) sum += num(a);

	} while(next_permutation(all(a)));
	cout << sum << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
