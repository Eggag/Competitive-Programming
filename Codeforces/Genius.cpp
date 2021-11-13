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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll t[mxN], s[mxN], mx[mxN];

void solve(){
	int n;
	cin >> n;
	rep(i, n) cin >> t[i], mx[i] = 0LL;
	rep(i, n) cin >> s[i];
	rep(i, n) for(int j = i - 1; j >= 0; j--) if(t[i] != t[j]){
		ll mx1 = mx[i];
		mx[i] = max(mx[i], abs(s[i] - s[j]) + mx[j]);
		mx[j] = max(mx[j], abs(s[i] - s[j]) + mx1);
	}
	ll ans = 0LL;
	rep(i, n) ans = max(ans, mx[i]);
	cout << ans << '\n';
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
