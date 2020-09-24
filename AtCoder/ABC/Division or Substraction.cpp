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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	if(n == 2){
		cout << 1 << endl;
		return 0;
	}
	set<ll> ans;
	ans.insert(n);
	ans.insert(n - 1);
	for(ll i = 2; (i * i) <= n; i++){
		if(n % i == 0){
			ll rep = n;
			while(rep % i == 0) rep /= i;
			if(rep % i == 1) ans.insert(i);
			if((n / i) != i){
				ll rep1 = n;
				while(rep1 % (n / i) == 0) rep1 /= (n / i);
				if(rep1 % (n / i) == 1) ans.insert(n / i);
			}
		}
	}
	n--;
	for(ll i = 2; (i * i) <= n; i++){
		if(n % i == 0){
			ll rep = n;
			if(rep % i == 0 && (n + 1) % i == 1) ans.insert(i);
			if((n / i) != i){
				ll rep1 = n;
				if(rep1 % (n / i) == 0 && (n + 1) % (n / i) == 1) ans.insert(n / i);
			}
		}
	}
	cout << ans.size() << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
