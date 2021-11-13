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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q, k;
	cin >> n >> q >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi p(n, 0);
	p[0] = a[1] - 2, p[n - 1] = k - a[n - 2] - 2;
	repn(i, 1, n - 1) p[i] = a[i + 1] - a[i - 1] - 2;
	repn(i, 1, n) p[i] += p[i - 1];
	rep(i, q){
		int l, r;
		cin >> l >> r;
		r--, l--;
		if(l == r) cout << k - 1 << '\n';
		else{
			cout << p[r - 1] - p[l] + (a[l + 1] - 2) + (k - a[r - 1] - 1) << '\n';
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
