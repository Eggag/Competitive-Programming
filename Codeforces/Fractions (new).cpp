#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	set<pair<ll, ll>> fr;
	for(ll i = 1LL; i <= 998; i++) for(ll j = 1LL; j <= 998; j++){
		ll g = gcd(i, j);
		ll i1 = i / g, j1 = j / g;
		if((i + j) < 1000) fr.insert({i1, j1});
	}
	ll ans = 0;
	for(pair<ll, ll> f : fr){
		ll ffi = f.fi, fse = f.se;
		ll mult = 1LL, mult1 = 1LL;
		if(ffi < a) mult = (a + f.fi - 1) / ffi;
		if(fse < c) mult1 = (c + f.se - 1) / fse;
		ffi *= max(mult, mult1);
		fse *= max(mult, mult1);
		if(ffi > b || fse > d) continue;
		ll num = ((b / f.fi) - ((ffi - 1) / f.fi));
		ll num1 = ((d / f.se) - ((fse - 1) / f.se));
		ll cur = min(num, num1);
		ans += cur;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
