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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), b, c;
	rep(i, n){
		cin >> a[i];
		if(a[i] >= 0) b.pb(a[i]);
		else c.pb(-1 * a[i]);
	}
	sort(all(b));
	sort(all(c));
	ll ans = 0LL;
	int n1 = b.size(), n2 = c.size();
	rep(i, n1){
		auto it = ub(all(b), b[i] + b[i]);
		ans += (it - b.begin()) - i - 1;
	}
	rep(i, n2){
		auto it = ub(all(c), c[i] + c[i]);
		ans += (it - c.begin()) - i - 1;
	}
	rep(i, n1){
		auto it = ub(all(c), b[i] + b[i]);
		auto it1 = lb(all(c), b[i] + 1);
		ans += (it - c.begin()) - (it1 - c.begin());
	}
	rep(i, n2){
		auto it = ub(all(b), c[i] + c[i]);
		auto it1 = lb(all(b), c[i]);
		ans += (it - b.begin()) - (it1 - b.begin());
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
