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

void solve(){
	int n;
	cin >> n;
	vector<pi> ans;
	if(n <= 30){
		repn(i, 2, n - 1) ans.pb(mp(i, i + 1));
		ans.pb(mp(n, n - 1));
		int cr = n - 1;
		while(cr != 1){
			ans.pb(mp(n - 1, n));
			cr = (cr + 1) / 2;
		}
	}
	else{
		int f = (n % 3 == 0 ? 0 : 1);
		int num = (n / 3) + f;
		ans.pb(mp(n, num));
		repn(i, 3, n - 1) if(i != 27) ans.pb(mp(i, i + 1));
		//we have 2, 27, n - 1, 3 (at n)
		int cr = n - 1;
		while(cr != 1){
			ans.pb(mp(n - 1, 27));
			cr = (cr + 26) / 27;
		}
		cr = 27;
		while(cr != 1){
			ans.pb(mp(27, n));
			cr = (cr + 2) / 3;
		}
		ans.pb(mp(n, 2));
		ans.pb(mp(n, 2));
	}
	assert(ans.size() <= (n + 5));
	cout << (int)(ans.size()) << '\n';
	for(pi x : ans) cout << x.fi << " " << x.se << '\n';
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
