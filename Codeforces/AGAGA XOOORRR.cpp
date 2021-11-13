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

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi l(n, 0), r(n + 1, 0);
	l[0] = a[0], r[n - 1] = a[n - 1];
	repn(i, 1, n) l[i] = l[i - 1] ^ a[i];
	for(int i = n - 2; i >= 0; i--) r[i] = r[i + 1] ^ a[i];
	int f = 0;
	rep(i, n - 1) if(l[i] == r[i + 1]) f = 1;
	rep(i, n) repn(j, i + 1, n - 1){
		int le = l[i];
		int ri = r[j + 1];
		int mid = r[0] ^ le ^ ri;
		if(le == ri && le == mid) f = 1;
	}	
	cout << (f ? "YES" : "NO") << '\n';
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
