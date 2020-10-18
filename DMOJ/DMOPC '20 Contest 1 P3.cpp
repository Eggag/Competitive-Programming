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
	vector<ll> a(n), b(n), c(n);
	rep(i, n) cin >> a[i], b[i] = a[i], c[i] = a[i];
	vector<ll> l(n), r(n); //we store the sum
	l[0] = 0LL;
	repn(i, 1, n){
		l[i] = l[i - 1];
		l[i] += max(0LL, a[i - 1] - a[i]);
		a[i] = max(a[i - 1], a[i]);
	}
	r[n - 1] = 0LL;
	for(int i = n - 2; i >= 0; i--){
		r[i] = r[i + 1];
		r[i] += max(0LL, b[i + 1] - b[i]);
		b[i] = max(b[i + 1], b[i]);
	}
	ll bst = 1e18;
	rep(i, n){
		ll mx = -1e18, tot = 0LL;
		if(i) tot += l[i - 1], mx = max(mx, a[i - 1]);
		if(i < (n - 1)) tot += r[i + 1], mx = max(mx, b[i + 1]);
		bst = min(bst, tot + max(0LL, mx - c[i]));
	}
	cout << bst << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
