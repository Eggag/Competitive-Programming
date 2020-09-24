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

bool prime(ll n){
	for(ll i = 2; (i * i) <= n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll ans = 0;
	for(int i = 9; i >= 1; i--){
		vi a;
		repn(j, 1, i + 1) a.pb(j);
		do{
			ll cur = 0;
			ll mult = 1;
			reverse(all(a));
			rep(i, a.size()) cur += mult * a[i], mult *= 10;
			reverse(all(a));
			if(prime(cur)) ans = max(ans, cur);
		} while(next_permutation(all(a)));
		if(ans != 0){
			cout << ans << endl;
			return 0;
		}
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
