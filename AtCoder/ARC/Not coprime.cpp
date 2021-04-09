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
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vi p;
	for(int i = 2; i <= 50; i++){
		int f = 1;
		for(int j = 2; (j * j) <= i; j++){
			if(i % j == 0) f = 0;
		}
		if(f) p.pb(i);
	}
	ll mn = 1e18;
	rep(i, 1 << (int)(p.size())){
		int f = 1;
		ll num = 1LL;
		rep(j, p.size()) if(i & (1 << j)) num *= (ll)(p[j]);
		rep(j, n) if(gcd(a[j], num) == 1) f = 0;
		if(f) mn = min(mn, num);
	}
	cout << mn << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
