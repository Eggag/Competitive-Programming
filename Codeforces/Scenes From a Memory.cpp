#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

bool prime(int n){
	if(n == 1) return 0;
	for(int i = 2; (i * i) <= n; i++) if(n % i == 0) return 0;
	return 1;
}

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, n){
		if(!prime((int)(s[i] - '0'))){
			cout << "1\n" << s[i] << '\n';
			return;
		}
	}
	rep(i, n) repn(j, i + 1, n){
		int nm = 10 * (int)(s[i] - '0') + (int)(s[j] - '0');
		if(!prime(nm)){
			cout << "2\n" << nm << '\n';
			return;
		}
	}
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
