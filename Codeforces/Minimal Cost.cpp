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
	int n, u, v;
	cin >> n >> u >> v;
	vi a(n);
	rep(i, n) cin >> a[i];
	int lst = a[0];
	int ans = 2e9 + 10;
	repn(i, 1, n){
		if(abs(lst - a[i]) > 1) ans = 0;
		if(!abs(lst - a[i])) ans = min({ans, 2 * v, u + v});
		if(abs(lst - a[i]) == 1){
			ans = min(ans, u);
			if(a[i] > lst && a[i] != (int)(1e6 + 1)) ans = min(ans, v);
			if(a[i] < lst && a[i] > 0) ans = min(ans, v);
		}
		lst = a[i];
	}
	cout << ans << endl;
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