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

bool valid(int a, int b, int c){
	return ((a != b) && (a != c) && (b != c));
}

void solve(){
	int n;
	cin >> n;
	//factor n
	vi factors;
	for(int i = 2; (i * i) <= n; i++){
		if(n % i == 0){
			factors.pb(i);
			if((n / i) != i) factors.pb(n / i);
		}
	}
	rep(j, factors.size()){
		//distinct, so no cubes
		//make factors[i] the one we are splitting
		for(int i = 2; (i * i) <= factors[j]; i++){
			if(factors[j] % i == 0 && ((n / i) != i) && valid(i, factors[j] / i, n / factors[j])){
				cout << "YES" << endl;
				cout << i << " " << factors[j] / i << " " << n / factors[j] << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
