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

int k;

ll solve(vi a){
	int pr = 0;
	int n = (int)(a.size());
	sort(all(a));
	ll ans = 0;
	rep(i, n){
		ll nm = ((n - i) + k - 1) / k;
		ans += (ll)(1 + (nm - 1) * 2) * (ll)(a[i] - pr);
		pr = a[i];
	}
	return ans;
}

void solve(){
	int n;
	cin >> n >> k;
	vi a(n), b, c;
	ll mx = 0, mx1 = 0;
	rep(i, n){
		cin >> a[i];
		if(a[i] > 0){
			b.pb(a[i]);
			mx = max(mx, (ll)(a[i]));
		}
		if(a[i] < 0){
			c.pb(-a[i]);
			mx1 = max(mx1, (ll)(-a[i]));
		}
	}
	ll uwu = 0;
	if(b.size() && c.size()) uwu = min(mx, mx1);
	cout << uwu + solve(b) + solve(c) << '\n';
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
