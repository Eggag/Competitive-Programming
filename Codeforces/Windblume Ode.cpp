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

bool prime(int c){
	for(int i = 2; (i * i) <= c; i++){
		if(c % i == 0) return 0;
	}
	return 1;
}

void solve(){
	int n;
	cin >> n;
	vi a(n);
	int sm = 0;
	rep(i, n) cin >> a[i], sm += a[i];
	if(!prime(sm)){
		cout << n << '\n';
		rep(i, n) cout << i + 1 << ' ';
		cout << '\n';
	}
	else{
		cout << n - 1 << '\n';
		int f = 1;
		rep(i, n){
			if(f && a[i] % 2 == 1){
				f = 0;
				continue;
			}
			cout << i + 1 << ' ';
		}
		cout << '\n';
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
